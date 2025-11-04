#include <iostream>
#include <vector>
#define MAX 100000
#define INF 1e9
using namespace std;
typedef long long ll;

vector<int> checktime(MAX);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int minTime = INF; // minimum time among all checkpoints
	int N, M; cin >> N >> M; // N : immigration checkpoint, M : number of people
	for (int i = 0; i < N; i++) {
		cin >> checktime[i];
		minTime = min(minTime, checktime[i]);
	}

	ll ans = (ll)minTime * M;
	ll left = 1; // min time
	ll right = (ll)minTime * M; // max time

	while (left <= right) { // binary search
		ll mid = (left + right) / 2;
		ll total = 0; // total number of people that can be processed in mid time
		for (int i = 0; i < N; i++) { // calculate how many people can be processed in mid time
			total += mid / checktime[i];
			if (total >= M) break; // if already can process M people, no need to continue
		}
		if (total >= M) { // if can process M people in mid time, try to find a smaller time
			right = mid - 1;
			ans = min(ans, mid);
		}
		else { // if cannot process M people in mid time, need more time
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
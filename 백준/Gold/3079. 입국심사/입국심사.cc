#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;
typedef long long ll;

vector<ll> checktime(MAX);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int N, M; cin >> N >> M; // N : immigration checkpoint, M : number of people
	for (int i = 0; i < N; i++) {
		cin >> checktime[i];
	}
	sort(checktime.begin(), checktime.begin() + N); // sort to get the minimum time easily
	ll ans = checktime[0] * M;
	ll left = 1; // min time
	ll right = checktime[0] * M; // max time

	while (left <= right) { // binary search
		ll mid = (left + right) / 2;
		ll total = 0; // total number of people that can be processed in mid time
		for (int i = 0; i < N; i++) { // calculate how many people can be processed in mid time
			total += mid / checktime[i];
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
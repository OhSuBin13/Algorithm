#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

bool visited[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K; cin >> N >> K;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0,N));

	while (!pq.empty()) {
		int time = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue;
		visited[cur] = true;

		if (cur == K) {
			cout << time;
			break;
		}

		int next_positions[3] = { cur * 2, cur - 1, cur + 1 };
		for (int i = 0; i < 3; i++) {
			int next = next_positions[i];
			if (next >= 0 && next < MAX && !visited[next]) {
				if(i == 0)
					pq.push(make_pair(time, next));
				else
					pq.push(make_pair(time+1, next));
			}
		}
	}
	return 0;
}
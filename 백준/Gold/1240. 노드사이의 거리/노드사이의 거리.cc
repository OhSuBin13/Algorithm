#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> v(N + 1);
	for(int i = 0; i < N - 1; i++) {
		int a, b, dst;
		cin >> a >> b >> dst;
		v[a].push_back({ b, dst });
		v[b].push_back({ a, dst });	
	}

	for (int i = 0; i < M; i++) {
		int nodeA, nodeB;
		queue<pair<int, int>> q;
		vector<bool> visited(N + 1, false);

		cin >> nodeA >> nodeB;
		q.push({ nodeA, 0 });
		visited[nodeA] = true;

		while (!q.empty()) {
			int curNode = q.front().first;
			int curDist = q.front().second;
			q.pop();

			if (curNode == nodeB) {
				cout << curDist << "\n";
				break;
			}

			for (auto& i : v[curNode]) {
				int nextNode = i.first;
				int nextDist = i.second;
				if (!visited[nextNode]) {
					visited[nextNode] = true;
					q.push({ nextNode, curDist + nextDist });
				}
			}
		}
	}
	return 0;
}
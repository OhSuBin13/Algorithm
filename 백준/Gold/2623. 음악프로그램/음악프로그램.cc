#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
using namespace std;

int N, M;
vector<vector<int>> actor;
queue<int> q;
int indegree[MAX];
vector<int> ans;

void Input() {
	cin >> N >> M;
	actor.resize(N+1);

	for (int i = 0; i < M; i++) {
		int a; cin >> a;

		vector<int> tmp;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;

			tmp.push_back(b);
		}

		for (int j = 1; j < tmp.size(); j++) {
			actor[tmp[j - 1]].push_back(tmp[j]);
			indegree[tmp[j]]++;
		}
	}
}

void TopologicSort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			ans.erase(ans.begin(), ans.end());
			ans.push_back(0);
			return;
		}

		int singer = q.front();
		ans.push_back(singer);
		q.pop();

		for (int j = 0; j < actor[singer].size(); j++) {
			int y = actor[singer][j];

			if (--indegree[y] == 0) {
				q.push(y);
			}
		}
	}
}

void PrintAns() {
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}

void Solve() {
	TopologicSort();
	PrintAns();
}


void Solution() {
	Input();
	Solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}
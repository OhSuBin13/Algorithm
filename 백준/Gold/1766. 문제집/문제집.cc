#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int N, M;
int indegree[MAX];
priority_queue<int, vector<int>, cmp> q;
vector<vector<int>> problem;
vector<int> ans;

void Input() {
	cin >> N >> M;

	problem.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		problem[a].push_back(b);
		indegree[b]++;
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
			cout << "Input Error" << "\n";
			return;
		}

		int node = q.top();
		q.pop();
		ans.push_back(node);

		for (int i = 0; i < problem[node].size(); i++) {
			int y = problem[node][i];

			if (--indegree[y] == 0) {
				q.push(y);
			}
		}
	}
}

void PrintAns() {
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
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
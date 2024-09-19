#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
using namespace std;

int N, M;
vector<vector<int>> subject;
queue<pair<int,int>> q;
int indegree[MAX];
int semester[MAX];

void Input() {
	cin >> N >> M;
	
	subject.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;

		subject[a].push_back(b);
		indegree[b]++;
	}
}

void topologicalSort() {
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(make_pair(i,1));
			semester[i] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			cout << "not topology" << "\n";
			return;
		}

		int vertex = q.front().first;
		int year = q.front().second;

		q.pop();

		for (int i = 0; i < subject[vertex].size(); i++) {
			int y = subject[vertex][i];

			if (--indegree[y] == 0) {
				q.push(make_pair(y, year + 1));
				semester[y] = year + 1;
			}
		}
	}
}

void Solve() {
	topologicalSort();
	for (int i = 1; i <= N; i++) {
		cout << semester[i] << " ";
	}
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
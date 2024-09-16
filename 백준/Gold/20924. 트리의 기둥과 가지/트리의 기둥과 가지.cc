#include <iostream>
#include <vector>
#include <queue>

#define MAX 200001
using namespace std;

int N, R;
vector<vector<pair<int,int>>> tree;
int column;
int columnLength, branchLength;
bool visited[MAX];
int res = 0;

void Input() {
	cin >> N >> R;

	tree.resize(N + 1);

	for (int i = 0; i < N-1; i++) {
		int a, b, d;
		cin >> a >> b >> d;

		tree[a].push_back(make_pair(b,d));
		tree[b].push_back(make_pair(a,d));
	}
}

void GetColumn() {
	queue<pair<int, int>> q;
	visited[R] = true;
	if (tree[R].size() >= 2) {
		column = R;
		columnLength = 0;
		return;
	}

	for (int i = 0; i < tree[R].size(); i++) {
		q.push(make_pair(tree[R][i].first, tree[R][i].second));
	}

	while (!q.empty()) {
		int vertex = q.front().first;
		int length = q.front().second;
		visited[vertex] = true;
		q.pop();

		if (tree[vertex].size() >= 3 || tree[vertex].size() == 1) {
			column = vertex;
			columnLength = length;
			return;
		}

		for (int i = 0; i < tree[vertex].size(); i++) {
			int nextVertex = tree[vertex][i].first;
			int nextLength = tree[vertex][i].second + length;

			if (visited[nextVertex] == true) continue;

			q.push(make_pair(nextVertex, nextLength));
		}
	}
}

void DFS(int idx, int length) {
	for (int i = 0; i < tree[idx].size(); i++) {
		int vertex = tree[idx][i].first;
		int currentLength = length + tree[idx][i].second;

		if (visited[vertex] == true) continue;
		visited[vertex] = true;
		res = (res < currentLength) ? currentLength : res;
		DFS(vertex, currentLength);
		visited[vertex] = false;
	}
}

void Solve() {
	vector<int> v;
	GetColumn();
	DFS(column, 0);
	cout << columnLength << " " << res;
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
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> v;

int dfs(int row, int col, int direction) {
	if (row == N) return 0;
	int res = v[row][col];
	if (row == 0) {
		if (col == M - 1) res += min(dfs(row + 1, col, 0), dfs(row + 1, col - 1, -1));
		else if (col == 0) res += min(dfs(row + 1, col, 0), dfs(row + 1, col + 1, 1));
		else res += min(dfs(row + 1, col, 0), min(dfs(row + 1, col + 1, 1), dfs(row + 1, col - 1, -1)));
	}
	else if (direction == -1) {
		if (col == M - 1) res += dfs(row + 1, col, 0);
		else res += min(dfs(row + 1, col, 0), dfs(row + 1, col + 1, 1));
	}
	else if (direction == 0) {
		if (col == M - 1) res += dfs(row + 1, col - 1, -1);
		else if (col == 0) res += dfs(row + 1, col + 1, 1);
		else res += min(dfs(row + 1, col - 1, -1), dfs(row + 1, col + 1, 1));
	}
	else {
		if (col == 0) res += dfs(row + 1, col, 0);
		else res += min(dfs(row + 1, col, 0), dfs(row + 1, col - 1, -1));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	v.resize(N);
	int ans = 10000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num; cin >> num;
			v[i].push_back(num);
		}
	}
	for (int i = 0; i < M; i++) {
		ans = min(ans, dfs(0, i, 0));
	}
	cout << ans;
	return 0;
}
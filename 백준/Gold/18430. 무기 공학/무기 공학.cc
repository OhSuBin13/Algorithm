#include <iostream>
#include <vector>	
using namespace std;

int N, M;
vector<vector<int>> v;
bool visited[5][5] = { false, };
int res = 0;
int mX[2] = { -1, 1};
int mY[2] = { -1, 1};

void Input() {
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < M; j++) {
			int num; cin >> num;
			v[i].push_back(num);
		}
	}
}

void DFS(int x, int y, int strength) {
	if (x == N - 1 && y == M) {
		res = (res > strength) ? res : strength;
		return;
	}

	if (y == M) {
		DFS(x + 1, 0, strength);
		return;
	}

	if (visited[x][y]) {
		DFS(x, y + 1, strength);
		return;
	}

	DFS(x, y + 1, strength);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int nx = x + mX[i];
			int ny = y + mY[j];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[x][ny] || visited[nx][y]) continue;

			visited[x][y] = true;
			visited[x][ny] = true;
			visited[nx][y] = true;

			int newStrength = strength + 2 * v[x][y] + v[nx][y] + v[x][ny];
			DFS(x, y + 1, newStrength);
			visited[x][y] = false;
			visited[x][ny] = false;
			visited[nx][y] = false;
		}
	}
}

void Solution() {
	DFS(0, 0, 0);
	cout << res;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Solve();

	return 0;
}
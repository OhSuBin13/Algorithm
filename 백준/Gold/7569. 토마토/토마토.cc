#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int tomato[100][100][100];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N, H; cin >> M >> N >> H; // M: col, N: row, H: height	
	queue<pair<int, piii>> q; // {day, {height, {row, col}}}
	int ans = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					q.push({ 0,{i, {j, k}} });
				}
			}
		}
	}

	while (!q.empty()) {
		int day = q.front().first;
		int z = q.front().second.first;
		int y = q.front().second.second.first;
		int x = q.front().second.second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (tomato[nz][ny][nx] == 0) {
				tomato[nz][ny][nx] = 1;
				q.push({ day + 1, {nz, {ny, nx}} });
				ans = max(ans, day + 1);
			}
		}
	}
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << ans;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define MAX 1000
using namespace std;

int n, m;
int arr[MAX][MAX];
bool visited[MAX][MAX] = { false, };
int ans[MAX][MAX];

int mX[4] = { -1,0,1,0 };
int mY[4] = { 0,1,0,-1 };

queue<pair<int, int>> q;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i,j });
				visited[i][j] = true;
				ans[i][j] = 0;
			}
		}
	}
}

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + mX[i];
			int ny = y + mY[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] == true) continue;
			if (arr[nx][ny] == 0) continue;

			visited[nx][ny] = true;
			q.push({ nx, ny });
			ans[nx][ny] = ans[x][y] + 1;
		}
	}
}

void Solve() {
	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && ans[i][j] == 0) cout << "-1" << " ";
			else cout << ans[i][j] << " ";
		}
		cout << "\n";
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
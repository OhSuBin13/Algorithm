#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N;
vector<vector<char>> studio;
vector<pair<int,int>> door;
queue<pair<int, int>> q;
int mX[4] = { -1,0,1,0 };
int mY[4] = { 0,-1,0,1 };
int res = 3000;
bool visited[50][50];
int dirX, dirY;
int DP[50][50][4];

void Input() {
	cin >> N;
	studio.resize(N);

	for (int i = 0; i < studio.size(); i++) {
		studio[i].resize(N);
	}

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 4; k++) {
				DP[i][j][k] = 3000;
			}
		}
	}

	for (int i = 0; i < studio.size(); i++) {
		string inform;
		cin >> inform;

		for (int j = 0; j < studio[i].size(); j++) {
			studio[i][j] = inform[j];

			if (studio[i][j] == '#') {
				door.push_back({ i,j });
			}
		}
	}
	dirX = door[1].first;
	dirY = door[1].second;
}

void DFS(int x, int y, int direction, int cnt) {
	visited[x][y] = true;
	int nX = x + mX[direction];
	int nY = y + mY[direction];

	if (nX < 0 || nX >= N || nY < 0 || nY >= N) return;

	if (nX == dirX && nY == dirY) {
		res = min(res, cnt);
		return;
	}
	else if (studio[nX][nY] == '*') {
		return;
	}
	else if (studio[nX][nY] == '.') {
		if (!visited[nX][nY]) {
			DFS(nX, nY, direction, cnt);
		}
		else if (visited[nX][nY] && DP[nX][nY][direction] > cnt) {
			DP[nX][nY][direction] = cnt;
			DFS(nX, nY, direction, cnt);
		}
	}
	else if (studio[nX][nY] == '!') {
		if (!visited[nX][nY]) {
			DFS(nX, nY, direction, cnt);
			DFS(nX, nY, (direction + 3) % 4, cnt + 1);
			DFS(nX, nY, (direction + 1) % 4, cnt + 1);
		}
		else if (visited[nX][nY]) {
			if (DP[nX][nY][direction] > cnt) {
				DP[nX][nY][direction] = cnt;
				DFS(nX, nY, direction, cnt);
			}

			if (DP[nX][nY][(direction + 1) % 4] > cnt + 1) {
				DP[nX][nY][(direction + 1) % 4] = cnt + 1;
				DFS(nX, nY, (direction + 1) % 4, cnt + 1);
			}

			if (DP[nX][nY][(direction + 3) % 4] > cnt + 1) {
				DP[nX][nY][(direction + 3) % 4] = cnt + 1;
				DFS(nX, nY, (direction + 3) % 4, cnt + 1);
			}
		}
		
	}
}

void Solution() {
	int firstDoorX = door[0].first;
	int firstDoorY = door[0].second;
	for (int i = 0; i < 4; i++) {
		DP[firstDoorX][firstDoorY][i] = 0;
		DFS(firstDoorX, firstDoorY, i, 0);
	}
	cout << res;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	Solve();
	return 0;
}

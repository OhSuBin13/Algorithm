#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

int R, C;
char MAP[MAX][MAX];
queue<pair<int, int>> changeToSea;

int dX[4] = { 0,1,0,-1 };
int dY[4] = { 1,0,-1,0 };

int minX = 20;
int minY = 20;
int maxX = 0;
int maxY = 0;

void Input() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
		}
	}
}

bool InBound(int x, int y) {
	return (x >= 0 && x < R && y >= 0 && y < C);
}

bool DisappearGround(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nX = x + dX[i];
		int nY = y + dY[i];
		if (!InBound(nX, nY)) {
			cnt++;
			continue;
		}

		if (MAP[nX][nY] == '.') cnt++;
	}

	return (cnt >= 3);
}

void ReSearchGroud() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == 'X' && DisappearGround(i,j)) {
				changeToSea.push(make_pair(i, j));
			}
		}
	}
}

void newMap() {
	while (!changeToSea.empty()) {
		int x = changeToSea.front().first;
		int y = changeToSea.front().second;
		changeToSea.pop();

		MAP[x][y] = '.';
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == 'X') {
				if (minX > i) minX = i;
				if (maxX < i) maxX = i;
				if (minY > j) minY = j;
				if (maxY < j) maxY = j;

			}
		}
	}
}

void Solve() {
	ReSearchGroud();
	newMap();

	for (int i = minX; i <= maxX; i++) {
		for (int j = minY; j <= maxY; j++) {
			cout << MAP[i][j];
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
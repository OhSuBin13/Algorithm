#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define MAX 99999999
using namespace std;

int grid[19][19];

void Input() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> grid[i][j];
		}
	}
}

bool InboundRow(int y) {
	return (y + 4 < 19);
}

bool InboundColumn(int x) {
	return (x + 4 < 19);
}

bool InboundCross(int x, int y) {
	return (x + 4 < 19 && y + 4 < 19);
}

bool ReverseCheckCross(int x, int y) {
	return (x -4 >= 0 && y + 4 < 19);
}

bool RowCheck(int x, int y) {
	if (!InboundRow(y)) return false;

	for (int i = 1; i < 5; i++) {
		if (grid[x][y + i] != grid[x][y + i - 1]) return false;
	}

	if (y + 5 < 19 && grid[x][y+5] == grid[x][y+4]) return false;

	if (y - 1 >= 0 && grid[x][y-1] == grid[x][y]) return false;

	return true;
}

bool ColumnCheck(int x, int y) {
	if (!InboundColumn(x)) return false;

	for (int i = 1; i < 5; i++) {
		if (grid[x + i][y] != grid[x + i-1][y]) return false;
	}

	if (x + 5 < 19 && grid[x + 5][y] == grid[x + 4][y]) return false;

	if (x - 1 >= 0 && grid[x - 1][y] == grid[x][y]) return false;

	return true;
}

bool CrossCheck(int x, int y) {
	if (!InboundCross(x,y)) return false;

	for (int i = 1; i < 5; i++) {
		if (grid[x + i][y + i] != grid[x + i - 1][y + i -1]) return false;
	}

	if (x + 5 < 19 && y + 5 < 19 && grid[x + 5][y + 5] == grid[x + 4][y + 4]) return false;

	if (x -1 >= 0 && y - 1 >= 0 && grid[x - 1][y - 1] == grid[x][y]) return false;

	return true;
}

bool ReverseCrossCheck(int x, int y) {
	if (!ReverseCheckCross(x, y)) return false;

	for (int i = 1; i < 5; i++) {
		if (grid[x - i][y + i] != grid[x - i + 1][y + i - 1]) return false;
	}

	if (x - 5 >= 0 && y + 5 < 19 && grid[x - 5][y + 5] == grid[x - 4][y + 4]) return false;

	if (x + 1 < 19 && y - 1 >= 0 && grid[x + 1][y - 1] == grid[x][y]) return false;

	return true;
}


void Backtracking(int cnt) {

}

void Solve() {
	bool flag = false;

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (grid[i][j] != 0) {
				if (RowCheck(i, j)) {
					cout << grid[i][j] << "\n";
					cout << i + 1 << " " << j + 1;
					flag = true;
				}
				else if (ColumnCheck(i, j)) {
					cout << grid[i][j] << "\n";
					cout << i + 1<< " " << j + 1;
					flag = true;
				}
				else if (CrossCheck(i, j)) {
					cout << grid[i][j] << "\n";
					cout << i + 1<< " " << j + 1;
					flag = true;
				}
				else if (ReverseCrossCheck(i, j)) {
					cout << grid[i][j] << "\n";
					cout << i + 1 << " " << j + 1;
					flag = true;
				}
			}
		}
	}
	if (flag == false) cout << "0";
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
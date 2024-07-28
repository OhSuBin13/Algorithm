#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 10
using namespace std;

int n;
char arr[MAX][MAX];
char play[MAX][MAX];
char result[MAX][MAX];
bool isBomb = false;

int mX[8] = { -1,-1,-1,0,0,1,1,1 };
int mY[8] = { -1,0,1,-1,1,-1,0,1 };

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> play[i][j];
		}
	}
}

bool InRange(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < n);
}

void CheckArray(int i, int j) {
	int res = 0;
	for (int k = 0; k < 8; k++) {
		int nI = i + mY[k];
		int nJ = j + mX[k];
		if (!InRange(nI, nJ)) continue;

		if (arr[nI][nJ] == '*') res++;

	}
	result[i][j] = (char)(res+48);
	
}

void CheckBomb() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '*') {
				isBomb = true;
			}
		}
	}
}

void Check(int i, int j) {
	if (arr[i][j] == '.') {
		if (play[i][j] == 'x') {
			CheckArray(i, j);
		}
		else if (play[i][j] == '.') {
			result[i][j] = '.';
		}
	}
	else if (arr[i][j] == '*') {
		if (play[i][j] == 'x') {
			CheckBomb();
		}
		else if (play[i][j] == '.') {
			result[i][j] = '.';
		}
	}
}


void Solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Check(i,j);
		}
	}

	if (isBomb) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == '*') {
					result[i][j] = '*';
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j];
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
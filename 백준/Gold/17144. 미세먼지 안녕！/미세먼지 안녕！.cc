#include <iostream>
#include <queue>

#define MAX 51
using namespace std;

//clock
int dX[4] = { 0,1,0,-1 };
int dY[4] = { 1,0,-1,0 };
//counter-clock
int counterdX[4] = { 0,-1,0,1 };
int counterdY[4] = { 1,0,-1,0 };

int ans = 0;
int R, C, T;
int A[MAX][MAX];
queue<pair<int, pair<int, int>>> dust;

void Input() {
	cin >> R >> C >> T; // row, column, time

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];
		}
	}
}

bool InBound(int x, int y) {
	return (x >= 0 && x < R && y >= 0 && y < C);
}

void CheckConfusion(int x, int y) {
	int res = A[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dX[i];
		int ny = y + dY[i];

		if (InBound(nx, ny) && A[nx][ny] != -1) {
			int amount = A[x][y] / 5;
			dust.push({ amount,{nx,ny} });
			res -= amount;
		}
	}
	A[x][y] = res;
}

void Confusion() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (A[i][j] > 0) {
				CheckConfusion(i, j);
			}
		}
	}

	while (!dust.empty()) {
		int x = dust.front().second.first;
		int y = dust.front().second.second;
		int amount = dust.front().first;

		dust.pop();

		A[x][y] += amount;
	}
}

void AirCondition(int x) {
	for (int i = x-1; i > 0; i--) {
		A[i][0] = A[i - 1][0];
	}
	for (int i = 0; i < C-1; i++) {
		A[0][i] = A[0][i+1];
	}
	for (int i = 0; i < x; i++) {
		A[i][C-1] = A[i + 1][C-1];
	}
	for (int i = C-1; i > 0; i--) {
		A[x][i] = A[x][i - 1];
		if (i == 1) {
			A[x][i] = 0;
		}
	}

	for (int i = x + 2; i < R - 1; i++) {
		A[i][0] = A[i + 1][0];
	}
	for (int i = 0; i < C - 1; i++) {
		A[R-1][i] = A[R-1][i + 1];
	}
	for (int i = R-1; i > x + 1; i--) {
		A[i][C - 1] = A[i - 1][C - 1];
	}
	for (int i = C - 1; i > 0; i--) {
		A[x+1][i] = A[x+1][i - 1];
		if (i == 1) {
			A[x+1][i] = 0;
		}
	}
}

void Check() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Sum() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (A[i][j] > 0) ans += A[i][j];
		}
	}
}


void Solve() {
	int x = 0;
	for (int i = 0; i < R; i++) {
		if (A[i][0] == -1) {
			x = i;
			break;
		}
	}

	while (T--) {
		Confusion();
		//Check();
		AirCondition(x);
		//Check();
	}
	Sum();
	cout << ans;
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


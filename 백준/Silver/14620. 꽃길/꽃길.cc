#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 100000000
using namespace std;

int N;
int arr[10][10];
int comb[3] = { 0, };
bool visited[100] = { false, };
int res = MAX;
int mX[5] = { 0,1,0,-1,0 };
int mY[5] = { 0,0,1,0,-1 };
int checkArr[10][10];
int tmp[3] = { 7, 10, 25 };

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

bool InBoundary(int x, int y) {
	return ((x - 1) >= 0 && (x + 1) < N && (y - 1) >= 0 && (y + 1) < N);
}

bool check(int comb[3]) {
	for (int i = 0; i < 3; i++) {
		int x = comb[i] / N;
		int y = comb[i] % N;

		if (!InBoundary(x, y)) return false;

		for (int j = 0; j < 5; j++) {
			int nx = x + mX[j];
			int ny = y + mY[j];

			checkArr[nx][ny]++;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (checkArr[i][j] > 1) {
				return false;
			}
		}
	}

	return true;
}

void ResetCheckArr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			checkArr[i][j] = 0;
		}
	}
}

void Backtracking(int cnt, int pos) {
	if (cnt == 3) {
		ResetCheckArr();
		if (check(comb)) {
			
			int sum = 0;
			for (int i = 0; i < 3; i++) {
				int x = comb[i] / N;
				int y = comb[i] % N;

				for (int j = 0; j < 5; j++) {
					int nx = x + mX[j];
					int ny = y + mY[j];

					sum += arr[nx][ny];
				}
			}
			res = min(res, sum);
		};
		return;
	}

	for (int i = pos; i < N * N; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		comb[cnt] = i;
		Backtracking(cnt + 1, i);
		visited[i] = false;
	}
}

void Solve() {
	Backtracking(0, 0);
	cout << res;
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
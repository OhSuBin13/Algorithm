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
int W[10][10];
int visited[10] = { false, };
int res = MAX;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
}

void Backtracking(int num, int pos, int sum, int start) {

	if (num == N) {
		if (W[pos][start] != 0) {
			res = min(res, sum + W[pos][start]);
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (W[pos][i] == 0) continue;

		if (visited[i] == true) continue;

		visited[i] = true;

		Backtracking(num + 1, i, sum + W[pos][i], start);

		visited[i] = false;
	}
}

void Solve() {
	for (int i = 0; i < 10; i++) {
		visited[i] = true;
		Backtracking(1, i, 0, i);
		visited[i] = false;
	}
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
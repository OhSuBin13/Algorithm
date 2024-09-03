#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define MAX 301
using namespace std;

int N, M, K;
int arr[MAX][MAX];
int i, j, x, y;
int sum[MAX][MAX] = { 0, };

void Input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + arr[i][j];
		}
	}

}

void Solve() {
	int res = 0;
	res = sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1];
	cout << res << "\n";
}

void Solution() {
	Input();
	cin >> K;
	for (int n = 0; n < K; n++) {
		cin >> i >> j >> x >> y;
		Solve();

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}


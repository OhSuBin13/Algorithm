#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define MAX 1025
using namespace std;

int arr[MAX][MAX] = { 0, };
int N, M;
int sum[MAX][MAX] = { 0, };
int a, b, c, d;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}

void PrefixSum() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i-1][j-1] + arr[i][j];
		}
	}
}

void Solve() {
	int res = 0;
	res = sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
	cout << res << "\n";
}

void Solution() {
	Input();
	PrefixSum();
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
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


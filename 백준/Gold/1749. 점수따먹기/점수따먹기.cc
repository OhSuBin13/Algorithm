#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define MAX 201
using namespace std;

int N, M;
int arr[MAX][MAX];
int sum[MAX][MAX];

void Input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

void PrefixSum() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + arr[i][j] - sum[i - 1][j - 1];
		}
	}
}

void Solve() {
	PrefixSum();
	long long int max_num = -1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = i; k <= N; k++) {
				for (int m = j; m <= M; m++) {
					int num = sum[k][m] - sum[k][j - 1] - sum[i - 1][m] + sum[i - 1][j - 1];
					if (num > max_num) max_num = num;
				}
			}
		}
	}
	cout << max_num;
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


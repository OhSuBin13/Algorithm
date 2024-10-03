#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX 501
using namespace std;

int N;
int m[MAX][2];
int DP[MAX][MAX];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> m[i][0] >> m[i][1];
	}
}

void Matrix() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; i + j <= N; j++) {
			DP[j][i + j] = INT_MAX;
			for (int k = j; k <= i + j; k++) {
				DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + m[j][0] * m[k][1] * m[i + j][1]);
			}
		}
	}
}

void Solve() {
	Matrix();

	cout << DP[1][N];
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

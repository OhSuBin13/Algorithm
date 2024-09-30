#include <iostream>

#define MAX 1025
using namespace std;

int N, M, K;
int arr[MAX][MAX];
int DP[MAX][MAX];

void Input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

void Solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			DP[i][j] = DP[i - 1][j] + DP[i][j-1] - DP[i-1][j - 1] + arr[i][j];
		}
	}
}


void Solution() {
	Input();
	Solve();

	int x1, y1, x2, y2;
	int res = 0;
	cin >> K;
	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;
		res = DP[x2][y2] + DP[x1 - 1][y1 - 1] - DP[x2][y1 - 1] - DP[x1 - 1][y2];
		cout << res << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];

int main() {

	int N, M;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][k] != 0 && arr[k][j] != 0 && i != j) {
					if (arr[i][j] == 0) arr[i][j] = arr[i][k] + arr[k][j];
					else arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (arr[a][b] <= c) {
			cout << "Enjoy other party" << "\n";
		}
		else {
			cout << "Stay here" << "\n";
		}
	}

	return 0;
}
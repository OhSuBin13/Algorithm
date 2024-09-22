#include <iostream>

#define MAX 101
#define INF 1e9
using namespace std;

int N, M;
int arr[MAX][MAX];

void Input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 0;
	}

}

void Floyd_WarShall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1) {
					arr[i][j] = 1;
					arr[j][i] = 0;
				}
				else if (arr[i][k] == 0 && arr[k][j] == 0) {
					arr[i][j] = 0;
					arr[j][i] = 1;
				}
			}
		}
	}
}

void Check() {
	for (int i = 1; i <= N; i++) {
		int num = 0;
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == INF && i != j) {
				num++;
			}
		}
		cout << num << "\n";
	}
}

void Check2() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void Solve() {
	Floyd_WarShall();
	Check();
}


void Solution() {
	Input();
	//Check2();
	Solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#define MAX 501
using namespace std;

int n, T, d;
int arr[MAX][MAX];
int tmp[MAX][MAX];

void Input() {
	cin >> n >> d;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
}

//시계방향
void TurnRight(int d) {	
	while (d > 0) {

		for (int i = 1; i <= n; i++) {
			tmp[i][i] = arr[i][i];
		}

		for (int i = 1; i <= n; i++) {
			arr[i][i] = arr[(n + 1) / 2][i];
		}

		for (int i = 1; i <= n; i++) {
			arr[(n + 1) / 2][i] = arr[n - i + 1][i];
		}

		for (int i = 1; i <= n; i++) {
			arr[n - i + 1][i] = arr[n - i + 1][(n + 1) / 2];
		}

		for (int i = 1; i <= n; i++) {
			arr[n - i + 1][(n + 1) / 2] = tmp[n - i + 1][n - i + 1];
		}

		d -= 45;
	}
}

//반시계방향
void TurnLeft(int d) {
	
	while (d < 0) {
		for (int i = 1; i <= n; i++) {
			tmp[i][i] = arr[i][i];
		}

		for (int i = 1; i <= n; i++) {
			arr[i][i] = arr[i][(n + 1) / 2];
		}

		for (int i = 1; i <= n; i++) {
			arr[i][(n + 1) / 2] = arr[i][n - i + 1];
		}

		for (int i = 1; i <= n; i++) {
			arr[i][n - i + 1] = arr[(n + 1) / 2][n - i + 1];
		}

		for (int i = 1; i <= n; i++) {
			arr[(n + 1) / 2][n - i + 1] = tmp[n - i + 1][n - i + 1];
		}

		d += 45;
	}
}

void Solve() {
	if (d < 0) {
		TurnLeft(d);
	}
	else if(d > 0){
		TurnRight(d);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void Solution() {
	Input();
	Solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		Solution();
	}

	return 0;
}


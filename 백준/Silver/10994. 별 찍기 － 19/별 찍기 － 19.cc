#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 400
using namespace std;

int N;
char arr[MAX][MAX];

void Input() {
	cin >> N;

	for (int i = 0; i < 4 * (N - 1) + 1; i++) {
		for (int j = 0; j < 4 * (N - 1) + 1; j++) {
			arr[i][j] = ' ';
		}
	}
}

void Solve() {
	int tmp = N;
	while (tmp) {
		for (int i = (N - tmp) * 2; i < (N - tmp) * 2 + 4 * (tmp - 1) + 1; i++) {
			for (int j = (N - tmp) * 2; j < (N - tmp) * 2 + 4 * (tmp - 1) + 1; j++) {
				if (j == (N - tmp) * 2 || j == (N - tmp) * 2 + 4 * (tmp - 1) ||
					i == (N - tmp) * 2 || i == (N - tmp) * 2 + 4 * (tmp - 1))
				{
					arr[i][j] = '*';
					//cout << i << " " << j << "\n";
				}
				//cout << i << " " << j << "\n";
				
			}
		}
		tmp -= 1;
	}

	for (int i = 0; i < 4 * (N - 1) + 1; i++) {
		for (int j = 0; j < 4 * (N - 1) + 1; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	//cout << arr[0][0];
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
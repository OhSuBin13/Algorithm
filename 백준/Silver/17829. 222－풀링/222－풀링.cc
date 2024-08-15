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
int arr[1024][1024];
int mX[4] = { 0,1,0,1 };
int mY[4] = { 1,0,0,1 };

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}

void Solve() {
	while (N != 1) {
		for (int i = 0; i < N; i += 2) {
			for (int j = 0; j < N; j += 2) {
				int num;
				vector<int> v;
				for (int k = 0; k < 4; k++) {
					int ni = i + mX[k];
					int nj = j + mY[k];
					v.push_back(arr[ni][nj]);
				}

				sort(v.begin(), v.end());

				int nextI = i / 2;
				int nextJ = j / 2;
				arr[nextI][nextJ] = v[2];
			}
		}
		N = N / 2;
	}
	cout << arr[0][0];
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
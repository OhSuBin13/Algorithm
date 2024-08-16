#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 100000000
using namespace std;

int n;
int DP[50001];

void Input() {
	cin >> n;

	for (int i = 0; i < 50001; i++) {
		DP[i] = 10;
	}

	for (int i = 1; i <= sqrt(50001); i++) {
		DP[i * i] = 1;
	}
}

void Solve() {
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= 50000; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			DP[i] = min(DP[i], DP[j * j] + DP[i - j * j]);
		}
	}
	cout << DP[n];
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
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define MAX 99999999
using namespace std;

int N;
long long int DP[91];

void Input() {
	cin >> N;
}

void Solve() {
	DP[0] = 0;
	DP[1] = 1;

	for (int i = 2; i <= 90; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N];
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
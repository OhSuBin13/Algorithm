#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n;
int res = 0;
long long dp[100001] = { 0, 1, 2, 2, 3, 3, 6, };

void Input() {
	cin >> n;
}

void Solution() {
	for (int i = 7; i <= 100000; i++) {
		dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % 1000000009;
	}
}

void Solve() {
	
	Input();
	Solution();
	//cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	
	cin >> T;
	Solution();
	while (T--) {
		Input();
		cout << dp[n] << "\n";
	}

	return 0;
}
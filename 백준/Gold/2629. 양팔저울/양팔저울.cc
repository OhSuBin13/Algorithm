#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, bead, x, weight[31];
bool dp[31][15001];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
}

void Recur(int i, int w) {
	if (i > n || dp[i][w]) return;
	dp[i][w] = true;

	Recur(i + 1, w + weight[i]);
	Recur(i + 1, abs(w - weight[i]));
	Recur(i + 1, w);
}

void Solve() {
	Recur(0, 0);
}


void Solution() {
	Input();
	Solve();

	cin >> bead;

	for (int i = 0; i < bead; i++) {
		cin >> x;

		if (x > 15000) cout << "N ";
		else if (dp[n][x]) cout << "Y ";
		else cout << "N ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}

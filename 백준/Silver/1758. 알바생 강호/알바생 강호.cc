#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 100000
using namespace std;

int row[MAX];
int n;
long long res = 0;

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> row[i];
	}
	sort(row, row + n);
}

int Tip(int money, int rank) {
	if (money - (rank - 1) <= 0) return 0;
	return (money - (rank - 1));
}

void Solve() {
	int rank = 1;
	for (int i = n-1; i >= 0; i--) {
		if (Tip(row[i], rank) == 0) {
			continue;
		}
		res += Tip(row[i], rank);
		rank++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();
	cout << res;

	return 0;
}
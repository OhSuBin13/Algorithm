#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 100000
using namespace std;

int rope[MAX];
int n, maxRange, minRange;

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + n);
}

int Solve() {
	int res = n * rope[0];
	for (int i = 1; i < n; i++) {
		res = max(res, (n - i) * rope[i]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	cout << Solve();

	return 0;
}
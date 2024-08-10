#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define MAX 10001
using namespace std;

int a, b, c, d, e, f, x, y;
int res = 0;

void Input() {
	cin >> a >> b >> c >> d >> e >> f;
}

void Solve() {
	if (b * d - e * a != 0)
		y = (c * d - f * a) / (b * d - e * a);
	else y = 0;

	if (a != 0)
		x = (c - b * y) / a;
	else x = (f - e * y) / d;
	cout << x << " " << y;
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
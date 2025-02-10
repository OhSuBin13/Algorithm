#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;
typedef long long L;
int n, i, l = -1e9, r = 1e9, m;
L x, y, a[N], b[N], q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i] >> b[i];
	while (l <= r) {
		m = (l + r) / 2;
		for (x = y = i = 0; i < n; i++) {
			x += abs(a[i] - m) * b[i];
			y += abs(a[i] - (m + 1)) * b[i];
		}
		if (x <= y) r = m - 1;
		else l = m + 1;
	}
	cout << l;
}
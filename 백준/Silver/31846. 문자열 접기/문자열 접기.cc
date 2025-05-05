#include <iostream>	
using namespace std;

int N, Q;
string s;

void Input() {
	cin >> N >> s >> Q;
}

void Solution() {
	int l, r;
	while (Q--) {
		int ans = 0;
		cin >> l >> r;
		l = l - 1;
		r = r - 1;
		float mid = l + 0.5;
		float diff = 0.5;
		int tmp = 0;
		while (mid < r) {
			int tmp = 0;
			diff = 0.5;
			while (mid + diff <= r && mid - diff >= l) {
				if (s[mid + diff] == s[mid - diff]) {
					tmp++;
				}
				diff = diff + 1;
			}
			ans = max(ans, tmp);
			mid = mid + 1;
		}
		cout << ans << "\n";
	}
}

void Solve() {
	Input();
	Solution();
}

int main() {
	Solve();
	return 0;
}
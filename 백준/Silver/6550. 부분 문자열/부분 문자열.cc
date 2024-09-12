#include <iostream>
#include <string>
#include <stack>

using namespace std;
string s, t;

void Input() {

}


void Solve() {
	while (cin >> s >> t) {
		int idx = 0;
		for (int i = 0; i < t.length(); i++) {
			if (s[idx] == t[i]) idx++;
		}
		if (idx == s.length()) {
			cout << "Yes" << "\n";
		}
		else cout << "No" << "\n";
	}
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
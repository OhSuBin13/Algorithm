#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;
	int totalZero = 0, totalOne = 0;
	for (auto& i : s) {
		if (i == '0') totalZero++;
		else totalOne++;
	}
	int zero = 0;
	int one = totalOne / 2;

	string ans = "";
	for (auto& i : s) {
		if (i == '1') {
			if (one) {
				one--;
			}
			else ans.push_back(i);
		}
		else {
			if (zero < totalZero / 2) {
				ans.push_back(i);
				zero++;
			}
		}
	}
	cout << ans;
	return 0;
}
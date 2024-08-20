#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 500000
using namespace std;

string s;

void Input() {
	cin >> s;
}

string FindMax(string s) {
	string res = "";
	int continuous = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'M') {
			continuous++;

			if (i == s.size() - 1) {
				string num = "1";

				for (int i = 0; i < continuous - 1; i++) {
					num += '1';
				}

				res += num;
				continuous = 0;
			}
		}
		else {
			string num = "5";

			for (int i = 0; i < continuous; i++) {
				num += '0';
			}

			res += num;
			continuous = 0;
		}
	}

	return res;
}

string FindMin(string s) {
	string res = "";
	int continuous = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'M') {
			continuous++;
			
			if (i == s.size() - 1 || s[i+1] == 'K') {
				string num = "1";

				for (int i = 0; i < continuous-1; i++) {
					num += '0';
				}

				res += num;
				continuous = 0;
			}
		}
		else {
			res += '5';
		}
	}


	return res;
}

void Solve() {
	cout << FindMax(s) << "\n";
	cout << FindMin(s);
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
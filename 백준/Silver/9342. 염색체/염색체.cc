#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;
string letter;

void Input() {
	cin >> T;
}


void Solve() {
	for (int i = 0; i < T; i++) {
		cin >> letter;

		bool A = false;
		bool F = false;
		bool C = false;
		bool lastNum = false;

		bool flag = true;

		if (letter[0] == 'A') A = true;

		for (int i = 1; i < letter.length(); i++) {
			if (!A) {
				if (letter[i] == 'A') {
					A = true;
				}
				else {
					flag = false;
				}
			}

			if (A && !F) {
				if (letter[i] == 'A') continue;
				else if (letter[i] == 'F') {
					F = true;
				}
				else {
					flag = false;
				}
			}

			if (A && F && !C) {
				if (letter[i] == 'F') continue;
				else if (letter[i] == 'C') {
					C = true;
				}
				else {
					flag = false;
				}
			}

			if (C) {
				if (letter[i] == 'C') continue;
				else {
					if (lastNum) {
						lastNum = true;
					}
					else {
						flag = false;
					}
				}
			}
		}

		if (flag) cout << "Infected!" << "\n";
		else cout << "Good" << "\n";
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
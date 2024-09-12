#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> vowel; // 모음 : 1 default : 0

void Input() {
	vowel['a'] = 1;
	vowel['e'] = 1;
	vowel['i'] = 1;
	vowel['o'] = 1;
	vowel['u'] = 1;
}


void Solve() {
	string pwd;
	while (cin >> pwd) {
		int conVowel = 0; //연속 모음
		int conConsonant = 0; //연속 자음
		bool containVowel = false;
		bool continuous = false;
		bool twoLetter = false;

		bool quality = true;

		for (int i = 0; i < pwd.size(); i++) {

			//모음을 하나 이상 소유하고 있는 지 판단
			if (!containVowel) {
				if (vowel[pwd[i]] == 1) containVowel = true;
			} 

			if (vowel[pwd[i]] == 1) {
				if (conConsonant != 0) {
					conConsonant = 0;
					conVowel = 1;
				}
				else {
					conVowel++;
				}
			}	
			else if (vowel[pwd[i]] == 0) {
				if (conConsonant != 0) {
					conConsonant++;
				}
				else {
					conVowel = 0;
					conConsonant = 1;
				}
			}

			if (conConsonant >= 3 || conVowel >= 3) continuous = true;

			if (i == 0) continue;

			if (pwd[i] == pwd[i - 1] && pwd[i] != 'e' && pwd[i] != 'o') {
				twoLetter = true;
			}
		}

		if (!containVowel) quality = false;

		if (continuous) quality = false;

		if (twoLetter) quality = false;

		if (pwd == "end") break;

		if (!quality) {
			cout << "<" << pwd << "> " << "is not acceptable." << "\n";
		}
		else {
			cout << "<" << pwd << "> " << "is acceptable." << "\n";
		}
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
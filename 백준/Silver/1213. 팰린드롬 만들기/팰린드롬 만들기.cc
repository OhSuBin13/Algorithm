#include <iostream>
#include <vector>
using namespace std;

int counter[26];
int odd = 0;
vector<char> v;
char oddNum;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		counter[(int)s[i] - 65]++;
	}

	for (int i = 0; i < 26; i++) {
		if (counter[i] % 2 == 1) odd++;
	}
	if (odd > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i < 26; i++) {
		if (counter[i] % 2 == 0) {
			int num = counter[i] / 2;
			while (num--) {
				v.push_back((char)(i + 65));
			}
		}
		else {
			int num = counter[i] / 2;
			while (num--) {
				v.push_back((char)(i + 65));
			}
			oddNum = (char)(i + 65);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	if (odd == 1) cout << oddNum;
	for (int i = 0; i < v.size(); i++) {
		cout << v[v.size() - 1 - i];
	}

	return 0;
}
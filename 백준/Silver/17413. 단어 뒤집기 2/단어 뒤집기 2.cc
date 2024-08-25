#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#define MAX 1000
using namespace std;

string s;
stack<char> word;

void Input() {
	getline(cin, s);
}

void Solve() {
	bool flag = false;

	for (int i = 0; i < s.size(); i++) {
		if (flag) {
			cout << s[i];
			if (s[i] == '>') {
				flag = false;
			}
			continue;
		}

		if (s[i] == '<') {
			while (!word.empty()) {
				cout << word.top();
				word.pop();
			}

			flag = true;
			cout << s[i];
			continue;
		}

		if (s[i] == ' ') {
			while (!word.empty()) {
				cout << word.top();
				word.pop();
			}
			cout << " ";
		}
		else {
			word.push(s[i]);
		}
	}

	if (!word.empty()) {
		while (!word.empty()) {
			cout << word.top();
			word.pop();
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
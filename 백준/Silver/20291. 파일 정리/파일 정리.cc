#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 1000
using namespace std;

int N;
map<string, int> m;
vector<string> v;

void Input() {
	string s;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		bool flag = false;
		string cmd = "";

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') {
				flag = true;
				continue;
			}

			if (flag) {
				cmd += s[i];
			}

		}

		if (m[cmd] == 0) v.push_back(cmd);
		m[cmd]++;
	}
}

void Solve() {
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " " << m[v[i]] << "\n";
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
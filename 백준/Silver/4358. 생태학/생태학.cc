#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define MAX 99999999
using namespace std;

map<string, int> m;
int N = 0;

void Input() {
	cout << fixed;
	cout.precision(4);
	string name;

	while (getline(cin, name)) {
		N++;
		m[name]++;
	}
}

void Solve() {
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << (double)iter->second / N * 100 << "\n";
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
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 1000
using namespace std;

string s;
vector<string> v;
int res = 0;
char arr[5] = { 'q','u','a','c','k' };

void Input() {
	cin >> s;
}

void Solve() {
	int duck = 0;
	bool flag = false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'q') {
			v.push_back("q");
			duck++;
			res = max(res, duck);
		}

		else {
			if (duck == 0) flag = true;

			int x;
			for (int j = 1; j < 5; j++) {
				if (arr[j] == s[i]) x = j;
			}
			
			for (int j = 0; j < v.size(); j++) {
				if (v[j].back() == arr[x - 1]) {
					v[j] += arr[x];
					if (x == 4) {
						v.erase(v.begin());
						duck--;
					}

					break;
				}

				if (j == v.size()-1) {
					flag = true;
				}
			}

		}
	}

	if (!v.empty()) flag = true;

	if (flag) cout << "-1";
	else cout << res;
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
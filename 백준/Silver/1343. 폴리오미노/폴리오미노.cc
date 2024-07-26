#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//void Input() {
//	
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s; // board, 'X', '.'
	string poliomino[2] = { "AAAA", "BB" };
	vector<int> v; // 'X','.' count
	vector<string> res; // result
	bool notWork = false; // check if it's impossible to divide
	int cnt = 0; // 'X' partial count

	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'X') {
			cnt++;
			if (i == s.length() - 1) v.push_back(cnt);
			if(i != s.length() - 1 && s[i+1] == '.') v.push_back(cnt);
		}
		else if (s[i] == '.') {
			cnt = 0;
			v.push_back(cnt);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 != 0) {
			notWork = true;
			break;
		}

		int four = v[i] / 4;
		int two = (v[i] % 4) / 2;

		for (int j = 0; j < four; j++) {
			res.push_back(poliomino[0]);
		}
		for (int j = 0; j < two; j++) {
			res.push_back(poliomino[1]);
		}
		if (v[i] == 0) res.push_back(".");
	}

	//test vector v
	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i] << " ";
	//} 

	//cout << "\n";

	if (notWork) cout << "-1";
	else {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
		}
	}

	return 0;
}
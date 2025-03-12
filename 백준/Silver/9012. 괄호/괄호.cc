#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int size = 0;
		for (auto x : s) {
			if (x == '(') size++;
			else {
				size--;
				if (size < 0) {
					cout << "NO" << "\n";
					break;
				}
			}
		}

		if(size == 0) cout << "YES" << "\n";
		else if(size > 0) cout << "NO" << "\n";
	}


	return 0;
}
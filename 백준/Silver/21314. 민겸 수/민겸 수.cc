#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	int size = s.size();
	string maxStr = "", minStr = "";
	int mNum = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'M') mNum++;
		else {
			maxStr += '5';
			for (int i = 0; i < mNum; i++) maxStr += '0';
			mNum = 0;
		}
	}
	if (mNum != 0) {
		for (int i = 0; i < mNum; i++) maxStr += '1';
	}
	mNum = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'M') mNum++;
		else {
			if (mNum) {
				minStr += '1';
				for (int i = 0; i < mNum - 1; i++) minStr += '0';
			}
			minStr += '5';
			mNum = 0;
		}
	}
	if (mNum != 0) {
		minStr += '1';
		for (int i = 0; i < mNum - 1; i++) minStr += '0';
	}
	
	cout << maxStr << "\n" << minStr << "\n";
	return 0;
}
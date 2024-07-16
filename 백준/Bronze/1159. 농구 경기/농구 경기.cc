#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	bool check = false;
	int N;
	int alpha[26] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;
		//cout << (int)'a';
		int num = (int)cmd[0] - 97;
		alpha[num]++;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] >= 5) {
			if (check == false) check = true;

			cout << (char)(i+97);
		}
	}

	if (!check) cout << "PREDAJA";

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
	string N; cin >> N;
	int NIdx = 0, num = 1;

	while (NIdx < N.length()) {
		string number = to_string(num);
		for (int i = 0; i < number.length(); i++) {
			if (N[NIdx] == number[i]) {
				NIdx++;
				if (NIdx >= N.length()) {
					cout << num;
					return 0;
				}
			}
		}
		num++;
	}
	return 0;
}
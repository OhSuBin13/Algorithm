#include <iostream>
#include <cmath>
#define MAX 1000000000
using namespace std;

int K;
int pos = 1;
string res;

int main() {
	cin >> K;

	for (int i = 1; i <= sqrt(MAX); i++) {
		if (K - pow(2, i) <= 0) {
			break;
		}
		K -= pow(2, i);
		pos++;
	}

	for (int i = pos - 1; i >= 0; i--) {
		int midLine = pow(2, i);
		if (K - midLine <= 0) {
			res.push_back('4');
		}
		else {
			res.push_back('7');
			K -= midLine;
		}
	}

	cout << res;
}
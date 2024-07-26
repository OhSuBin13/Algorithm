#include <iostream>
#include <algorithm>
using namespace std;

//void Input() {
//	
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int	twoWon, fiveWon = n / 5;
	int result = -1;

	while (fiveWon >= 0) {
		twoWon = (n - 5 * fiveWon) / 2;

		if((n - 5 * fiveWon) % 2 == 0){
			result = twoWon + fiveWon;
			break;
		}
		fiveWon--;
	}

	cout << result;

	return 0;
}
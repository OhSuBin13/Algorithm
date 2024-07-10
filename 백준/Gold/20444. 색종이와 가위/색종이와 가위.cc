#include <iostream>
#include <string>
using namespace std;

int main() {

	long long int n, k;
	cin >> n >> k;

	long long int high;
	long long int low;
	long long int mid;
	long long int paper;
	string ans = "NO";

	high = n/2;
	low = 0;

	while (high >= low) {
		mid = (high + low) / 2;
		paper = (mid + 1) * ((n - mid) + 1);
		
		if (paper == k) {
			ans = "YES";
			break;
		}
		else if (paper > k) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << ans;

	return 0;
}
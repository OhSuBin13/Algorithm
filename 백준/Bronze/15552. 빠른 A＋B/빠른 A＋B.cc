#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}
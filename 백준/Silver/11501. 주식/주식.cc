#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> prices(N);
		for (int i = 0; i < N; i++) {
			cin >> prices[i];
		}

		long long ans = 0;
		int max_price = -1;

		for (int i = N - 1; i >= 0; i--) {
			if (prices[i] > max_price) {
				max_price = prices[i];
			}
			else {
				ans += max_price - prices[i];
			}
		}

		cout << ans << "\n";

	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> S;
int res = 0;

void Input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		S.push_back(a);
	}
}

void TwoPointer() {
	int start = 0;
	int end = 0;
	int length = 0;
	int odd = 0;

	while (end != S.size()) {
		if (S[end] % 2 == 1) {
			odd++;
			while (odd > K) {
				if (S[start] % 2 == 1) odd--;

				start++;
			}
		}

		length = end - start + 1 - odd;
		res = (res < length) ? length : res;

		end++;
	}
}

void Solve() {
	TwoPointer();
	cout << res;
}

void Solution() {
	Input();
	Solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}
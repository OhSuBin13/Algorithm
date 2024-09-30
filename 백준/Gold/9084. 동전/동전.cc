#include <iostream>
#include <vector>
#include <cstring>

#define MAX 10001
using namespace std;

int T, N, M;
vector<int> coin;
int DP[MAX];

void Init() {
	coin.erase(coin.begin(), coin.end());
	memset(DP, 0, sizeof(DP));
}

void Input() {
	Init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		coin.push_back(num);
	}
	cin >> M;
}

void Solve() {
	DP[0] = 1;

	for (int i = 0; i < coin.size(); i++) {
		for (int j = coin[i]; j <= M; j++) {
			DP[j] = DP[j] + DP[j - coin[i]];
		}
	}
	cout << DP[M] << "\n";
}


void Solution() {
	cin >> T;

	while (T--) {
		Input();
		Solve();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}

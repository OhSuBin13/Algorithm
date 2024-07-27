#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 10
using namespace std;

int N, K;
int res = 0;
int coin_cost[MAX];

bool desc(int a, int b) {
	return a > b;
}

void Input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin_cost[i];
	}

	sort(coin_cost, coin_cost + N, desc);
}


void Solve() {
	for (int i = 0; i < N; i++) {
		if (K >= coin_cost[i]) {
			int multiply = K / coin_cost[i];
			res += multiply;
			K -= multiply * coin_cost[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();
	cout << res;

	return 0;
}
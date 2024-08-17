#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define MAX 99999999
using namespace std;

int N, K;
int arr[50001];
int d[50001][101];

void Input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

int DP(int x, int count, int length) {
	if (count > K || x <= 0) return length;

	if (d[x][count] != 0) return d[x][count];

	int value = 0;
	if (arr[x] % 2 == 0) value = DP(x - 1, count, length + 1);
	else if (count < K) value = DP(x - 1, count + 1, length);
	else if (count == K) return length;

	return d[x][count] = value;
}

void Solve() {
	int ans = 0;

	for (int i = N; i >= 1; i--) {
		for (int j = 0; j <= K; j++) {
			if (arr[i] % 2 == 0) ans = max(ans, DP(i, j, 0));
		}
	}
	cout << ans;
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
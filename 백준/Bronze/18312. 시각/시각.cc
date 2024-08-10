#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define MAX 10001
using namespace std;

int N, K;
int res = 0;

void Input() {
	cin >> N >> K;
}

void Solve() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 60; j++) {
			for (int x = 0; x < 60; x++) {
				if (i % 10 == K || i / 10 == K|| j % 10 == K || j / 10 == K || x % 10 == K || x / 10 == K) res++;
			}
		}
	}
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
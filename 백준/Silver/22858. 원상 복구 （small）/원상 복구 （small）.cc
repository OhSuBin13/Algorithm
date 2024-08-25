#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#define MAX 10001
using namespace std;

int N, K;
int S[MAX];
int D[MAX];
int tmp[MAX];

void Input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
	}
}

void Solve() {
	while (K--) {
		for (int i = 1; i <= N; i++) {
			tmp[D[i]] = S[i];
		}

		copy(begin(tmp), end(tmp), S);
	}

	for (int i = 1; i <= N; i++) {
		cout << S[i] << " ";
	}
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define MAX 100001
using namespace std;

int N;
int x[MAX];
int postSum = 0;
int preSum = 0;
long long int res = 0;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		postSum += x[i];
	}
}

void Solve() {
	for (int i = 0; i < N-1; i++) {
		preSum = x[i];
		postSum -= x[i];

		res += preSum * postSum;
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


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define MAX 100001
using namespace std;

int arr[MAX]= { 0, };
int N, Q;
int sum[MAX] = { 0, };
int x, y;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cin >> Q;
}

void PrefixSum() {
	for (int i = 2; i <= N; i++) {
		sum[i-1] = (arr[i] < arr[i - 1]) ? sum[i - 2] + 1 : sum[i - 2];
	}
}

void Solve() {
	int res = 0;
	res = sum[y-1] - sum[x - 1];
	cout << res << "\n";
}

void Solution() {
	Input();
	PrefixSum();
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
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


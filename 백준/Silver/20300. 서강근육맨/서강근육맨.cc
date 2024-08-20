#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 10000
using namespace std;

int N;
long long int M;
long long int arr[MAX];


void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
}

void Solve() {
	if (N % 2 == 0) {
		M = arr[0] + arr[N - 1];
		for (int i = 0; i < N / 2; i++) {
			M = max(M, arr[i] + arr[N - i - 1]);
		}
	}
	else {
		M = arr[N - 1];
		for (int i = 0; i < N / 2; i++) {
			M = max(M, arr[i] + arr[N - i - 2]);
		}
	}
	cout << M;
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
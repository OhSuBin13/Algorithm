#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 100000000
using namespace std;

long long int K;

void Input() {
	cin >> K;
}

long long int f(long long int num) {
	if (num == 1) return 0;
	long long int i;
	for (i = 1; i + i < num; i += i);
	return 1 - f(num - i);
}

void Solve() {
	cout << f(K);
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#define MAX 1000001
using namespace std;

int N, M, t;
long long int psum;
long long int res = 0;
long long mod[1001];


void Input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> t;
		psum += t;
		mod[psum % M]++;
	}
}

void PrefixSum() {

}

void Solve() {
	for (int i = 0; i < M; i++) {
		res += (mod[i] * (mod[i] - 1)) / 2;
	}
	
	res += mod[0];
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


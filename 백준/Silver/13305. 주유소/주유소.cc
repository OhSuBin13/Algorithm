#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 100000
using namespace std;

int N;
long long int city[MAX];
long long int dst[MAX - 1];
long long int res = 0;

void Input() {
	cin >> N;

	// 0~ (N-2)
	for (int i = 0; i < N -1; i++) {
		cin >> dst[i];
	}
	// 마지막 도시 저장 안함 0 ~ (N-2)
	for (int i = 0; i < N; i++) {
		cin >> city[i];
	}
}


void Solve() {
	int cost = city[0];
	res += cost * dst[0];

	for (int i = 1; i < N - 1; i++) {
		if (cost > city[i]) cost = city[i];
		res += cost * dst[i];
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
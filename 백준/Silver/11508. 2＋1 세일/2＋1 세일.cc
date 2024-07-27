#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define MAX 100000
using namespace std;

int dairy_product[MAX];
int N;
long long res = 0;

bool desc(int a, int b) {
	return a > b;
}

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> dairy_product[i];
	}

	sort(dairy_product, dairy_product + N, desc);
}


void Solve() {
	for (int i = 0; i < N; i++) {
		if ((i + 1) % 3 == 0) continue;
		res += dairy_product[i];
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
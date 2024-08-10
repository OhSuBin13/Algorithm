#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define MAX 10001
using namespace std;

int A, B, C, M;
int res = 0;

void Input() {
	cin >> A >> B >> C >> M;
}

void Solve() {
	int curPiro = 0;
	int t = 0;

	while (t < 24) {
		if (curPiro + A <= M) {
			curPiro += A;
			res += B;
		}
		else {
			curPiro -= C;
			if (curPiro < 0) curPiro = 0;
		}
		t++;
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
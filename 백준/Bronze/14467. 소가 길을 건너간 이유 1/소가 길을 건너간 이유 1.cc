#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 11
using namespace std;

int N;
int cow[MAX];
bool visited[MAX] = { false, };
int res = 0;

void Input() {
	cin >> N;
}

void Solve() {
	int num, pos;
	
	for (int i = 0; i < N; i++) {
		cin >> num >> pos;

		if (!visited[num]) {
			visited[num] = true;
			cow[num] = pos;
		}
		else {
			if (cow[num] != pos) res++;
			cow[num] = pos;
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
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>

#define MAX 31
using namespace std;

int N, T;
vector<int> v;

void Input() {
	cin >> N;

	v.erase(v.begin(), v.end());
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
}

void Solve() {
	cout << v[0] << " " << v[N - 1] << "\n";
}

void Solution() {
	for (int i = 0; i < T; i++) {
		Input();
		Solve();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	Solution();

	return 0;
}
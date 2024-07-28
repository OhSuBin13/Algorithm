#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>

#define MAX 31
using namespace std;
int arr[MAX] = { 0, };

void Input() {
	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;
		arr[num] = 1;
	}
}

void Solve() {
	for (int i = 1; i < MAX; i++) {
		if (arr[i] == 0) cout << i << "\n";
	}
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
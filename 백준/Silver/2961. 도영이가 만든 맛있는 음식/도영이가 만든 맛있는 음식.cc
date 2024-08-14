#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define MAX 99999999
using namespace std;

int N;
int S[10];
int B[10];
bool visited[10] = { false, };
int arr[10];
int res = MAX;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> B[i];
	}
}

void Backtracking(int cnt, int pos, int sour, int bit) {
	if (cnt == N) {

		return;
	}

	
	for (int i = pos; i < N; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		arr[cnt] = i;

		if (cnt == 0) sour = S[i];
		else sour *= S[i];
		bit += B[i];
		//cout << "sour: " << sour << " bit: " << bit << "\n";

		int diff = abs(sour - bit);
		res = min(res, diff);
		//cout << "diff: " << diff << " " << "res :" << res << " " << "\n";

		Backtracking(cnt + 1, i, sour, bit);
		visited[i] = false;

		if (cnt == 0) sour = 0;
		else sour /= S[i];
		bit -= B[i];
	}
}

void Solve() {
	Backtracking(0, 0, 0, 0);
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
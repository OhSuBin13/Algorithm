#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 100000000
using namespace std;

int N, M; 
int preference[30][30];
int arr[3];
int res = 0;
bool visited[30];

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> preference[i][j];
		}
	}
}

void Backtracking(int cnt, int pos) {
	if (cnt == 3) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int prefer = 0;
			for (int j = 0; j < 3; j++) {
				if (prefer < preference[i][arr[j]]) {
					prefer = preference[i][arr[j]];
				}
			}
			sum += prefer;
		}
		res = max(res, sum);
		return;
	}

	for (int i = pos; i < M; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		arr[cnt] = i;
		Backtracking(cnt + 1, i);
		visited[i] = false;
	}
}

void Solve() {
	Backtracking(0, 0);
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
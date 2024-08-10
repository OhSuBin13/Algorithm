#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define MAX 10001
using namespace std;

int N, M;
int arr[8];
int ans[8];
bool visited[8];

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
}

void Backtracking(int cnt, int pos) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = pos; i < N; i++) {
		if (tmp == arr[i]) continue;
		if (visited[i] == true) continue;

		visited[i] = true;
		ans[cnt] = arr[i];
		tmp = arr[i];
		Backtracking(cnt + 1, i);
		visited[i] = false;
	}
}

void Solve() {
	Backtracking(0, 0);
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
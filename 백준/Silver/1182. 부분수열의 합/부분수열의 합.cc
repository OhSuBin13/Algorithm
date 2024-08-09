#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 100000000
using namespace std;

int N, S; // 주어진 정수 개수, 목표 정수
int arr[21];
int visited[21] = { false, };
int res = 0;

void Input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void Backtracking(int cnt, int sum, int pos){
	if (cnt == N) {
		if (sum == S) res++;
		return;
	}

	if (sum == S) res++;

	for (int i = pos + 1; i < N; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		Backtracking(cnt + 1, sum + arr[i], i);
		visited[i] = false;
	}
}

void Solve() {
	for (int i = 0; i < N; i++) {
		visited[i] = true;
		Backtracking(0, arr[i], i);
		visited[i] = false;
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
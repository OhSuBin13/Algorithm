#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 100000000
using namespace std;

int N, M; // 주어진 정수 개수, 목표 정수
int arr[8];
bool visited[8] = {false,};
vector<int> v;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
}

void Backtracking(int cnt){
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		if (visited[i] == true) continue;

		if (tmp == arr[i]) continue;

		v.push_back(arr[i]);
		visited[i] = true;
		tmp = arr[i];
		Backtracking(cnt + 1);

		v.pop_back();
		visited[i] = false;
	}
}

void Solve() {
	Backtracking(0);
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
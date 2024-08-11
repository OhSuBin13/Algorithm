#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 100000000
using namespace std;

int H, W, N;
vector<pair<int, int>> paper; // R, C
bool visited[100];
int arr[2];
int res = 0;

void Input() {
	cin >> H >> W >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		paper.push_back(make_pair(a, b));
	}
}

void Backtracking(int cnt, int pos) {
	if (cnt == 2) {
		int firstA = paper[arr[0]].first;
		int firstB = paper[arr[0]].second;

		int secondA = paper[arr[1]].first;
		int secondB = paper[arr[1]].second;

		if ((firstA + secondA <= H && max(firstB, secondB) <= W) || (max(firstA, secondA) <= H && firstB + secondB <= W) ||
			(firstA + secondB <= H && max(firstB, secondA) <= W) || (max(firstA, secondB) <= H && firstB + secondA <= W) ||
			(firstB + secondA <= H && max(firstA, secondB) <= W) || (max(firstB, secondA) <= H && firstA + secondB <= W) ||
			(firstB + secondB <= H && max(firstA, secondA) <= W) || (max(firstB, secondB) <= H && firstA + secondA <= W)) {
			res = max(res, firstA * firstB + secondA * secondB);
		}

		return;
	}

	for (int i = pos; i < N; i++) {
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
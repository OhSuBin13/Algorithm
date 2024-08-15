#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 100000000
using namespace std;

int N;
vector<int> v;

bool bigger(int a, int b) {
	return a > b;
}

void Input() {
	cin >> N;
}

void Backtracking(int cnt, int pos) {

}

void Solve() {
	priority_queue<int, vector<int>, greater<int>> pq;
	int temp;
	for (int i = 0; i < N * N; i++) {
		cin >> temp;
		pq.push(temp);
		if (pq.size() > N) pq.pop();
	}
	cout << pq.top();
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
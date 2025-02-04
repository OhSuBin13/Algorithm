#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M;
vector<vector<char>> view;
vector<int> parent;

map<char, pair<int, int>> moving;

int find(int x) {
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
	x = find(x);
	y = find(y);
	
	if (x == y) return;
	else if (x > y) parent[x] = y;
	else parent[y] = x;
}

void Input() {
	cin >> N >> M;
	parent.resize(N * M);
	view.resize(N);
	for (int i = 0; i < N; i++) {
		view[i].resize(M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> view[i][j];
		}
	}

	for (int i = 0; i < parent.size(); i++) {
		parent[i] = i;
	}

	moving['D'] = { 1,0 };
	moving['U'] = { -1,0 };
	moving['L'] = { 0,-1 };
	moving['R'] = { 0,1 };
}

void Solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int mX = moving[view[i][j]].first;
			int mY = moving[view[i][j]].second;

			int nX = i + mX;
			int nY = j + mY;

			int base = i * M + j;
			int newBase = nX * M + nY;

			unionSets(base, newBase);
		}
	}

	map<int, bool> check;
	int res = 0;

	for (int i = 0; i < parent.size(); i++) {
		if (!check[find(i)]) {
			check[find(i)] = true;
			res++;
		}
	}

	cout << res;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	Solve();
	return 0;
}
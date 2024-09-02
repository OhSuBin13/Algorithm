#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;

int N, M, Answer; // N : 컴퓨터 수, M : Edge 갯수
int Parent[MAX];
vector<pair<int, pair<int, int>>> Edge;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge.push_back(make_pair(c, make_pair(a, b)));
	}
}

int Find(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = Find(Parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) Parent[y] = x;
}

bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

void Solve() {
	sort(Edge.begin(), Edge.end());
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		if (SameParent(Edge[i].second.first, Edge[i].second.second) == false) {
			Union(Edge[i].second.first, Edge[i].second.second);
			Answer = Answer + Edge[i].first;
		}
	}
	
	cout << Answer;
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


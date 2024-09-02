#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define MAX 1001
using namespace std;

int N, M;
int ans;
vector<pair<int, pair<int,int>>> Edge;
char Sex[MAX];
int Parent[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		char a;
		cin >> Sex[i];
	}

	for (int i = 0; i < M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		if (Sex[u] != Sex[v]) {
			Edge.push_back({ d,{u,v} });
		}
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

	for (int i = 0; i < Edge.size(); i++) {
		if (SameParent(Edge[i].second.first, Edge[i].second.second) == false) {
			Union(Edge[i].second.first, Edge[i].second.second);
			ans += Edge[i].first;
		}
	}

	bool flag = false;

	for (int i = 2; i <= N; i++) {
		if (SameParent(i, i - 1) == false) {
			flag = true;
			break;
		}
	}

	if (flag) cout << -1;
	else cout << ans;
}

void Solution() {
	Input();
	Solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(2);
	Solution();

	return 0;
}


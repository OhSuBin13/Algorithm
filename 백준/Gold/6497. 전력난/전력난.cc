#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
vector<bool> visited;
vector<int> parent;
int res = 0;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unionThem(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

void Input() {
	visited.resize(m);
	parent.resize(m);

	for (int i = 0; i < m; i++) {
		parent[i] = i;
	}

	while (!q.empty()) {
		q.pop();
	}
	res = 0;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		q.push({ z ,{x, y} });
	}
}

void Solution() {
	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int z = q.top().first;
		q.pop();

		//cout << x << " " << y << " " << z << "\n";
		if (visited[x] == false || visited[y] == false || find(x) != find(y)) {
			visited[x] = true;
			visited[y] = true;
			unionThem(x, y);
		}
		else {
			res += z;
		}
	}
}

void Solve() {
	Input();
	Solution();
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		Solve();
	}
	return 0;
}
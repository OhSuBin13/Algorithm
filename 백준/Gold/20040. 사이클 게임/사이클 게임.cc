#include <iostream>
#include <vector>
using namespace std;

int n, m;
int res = 0;
vector<bool> visited;
vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[x] = y;
	}
}

int main() {
	cin >> n >> m;
	visited.resize(n);
	parent.resize(n);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		a = find(a);
		b = find(b);
		if (a != b) {
			parent[a] = b;
		}
		else {
			res = i;
			break;
		}

		visited[a] = true, visited[b] = true;
	}

	cout << res;
}
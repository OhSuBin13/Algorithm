#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>	
using namespace std;

int N, res = 0;
vector<pair<int, pair<int, int>>> planet;
vector<pair<int, int>> v[3];
int parent[100001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;
	else if (x > y) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
	}
}

void Input() {
	cin >> N;
	planet.resize(N);

	for (int i = 0; i < planet.size(); i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[0].push_back({ x,i });
		v[1].push_back({ y,i });
		v[2].push_back({ z,i });
		parent[i] = i;
	}

	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());

	for (int i = 0; i < N - 1; i++) {
		planet.push_back(make_pair(abs(v[0][i].first - v[0][i + 1].first), make_pair(v[0][i].second, v[0][i + 1].second)));
		planet.push_back(make_pair(abs(v[1][i].first - v[1][i + 1].first), make_pair(v[1][i].second, v[1][i + 1].second)));
		planet.push_back(make_pair(abs(v[2][i].first - v[2][i + 1].first), make_pair(v[2][i].second, v[2][i + 1].second)));
	}

	sort(planet.begin(), planet.end());
}


void Solution() {
	for (int i = 0; i < planet.size(); i++) {
		int x = planet[i].second.first;
		int y = planet[i].second.second;
		int dist = planet[i].first;
		if (find(x) != find(y)) {
			unionSets(x, y);
			res += dist;
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define MAX 1001
using namespace std;

int N, M;
double ans;
vector<pair<int, int>> Vertex;
vector<pair<double, pair<int,int>>> Edge;
vector<pair<int, int>> visited;
int Parent[MAX];

void Input() {
	cin >> N >> M;
	Vertex.push_back({ 0,0 });

	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		Vertex.push_back(make_pair(a,b));
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		visited.push_back({ a,b });
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

double dst(int x1, int y1, int x2, int y2) {
	long long int x = pow(x1 - x2, 2);
	long long int y = pow(y1 - y2, 2);
	//cout << sqrt(x + y);
	return sqrt(x + y);
}

void Solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int x1 = Vertex[i].first;
			int y1 = Vertex[i].second;
			int x2 = Vertex[j].first;
			int y2 = Vertex[j].second;

			double dist = dst(x1, y1, x2, y2);
			Edge.push_back({ dist, {i,j} });
		}
	}

	sort(Edge.begin(), Edge.end());
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int x = visited[i].first;
		int y = visited[i].second;

		if(SameParent(x,y) == false) Union(x, y);
	}

	for (int i = 0; i < Edge.size(); i++) {
		if (SameParent(Edge[i].second.first, Edge[i].second.second) == false) {
			Union(Edge[i].second.first, Edge[i].second.second);
			ans += Edge[i].first;
		}
	}
	cout << ans;
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


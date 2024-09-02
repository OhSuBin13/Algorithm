#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000001
using namespace std;

int N;
long long int ans;
int Parent[MAX];
vector<pair<int, pair<int, int>>> Edge;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int c;
			cin >> c;
			Edge.push_back({ c, {i,j} });
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
		//cout << SameParent(Edge[i].second.first, Edge[i].second.second) << "\n";
		if (SameParent(Edge[i].second.first, Edge[i].second.second) == false) {
			Union(Edge[i].second.first, Edge[i].second.second);
			ans = ans + Edge[i].first;
			//cout << Edge[i].first << "\n";
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

	Solution();

	return 0;
}


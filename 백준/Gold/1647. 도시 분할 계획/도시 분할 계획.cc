#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000001
using namespace std;

int N, M, Answer;
vector<pair<int, pair<int, int>>> Edge;
int Parent[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		Edge.push_back({c,{a,b}});
	}
}

int Find(int x) {
	if (Parent[x] == x) return x;
	else return Parent[x] = Find(Parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if(x != y) Parent[y] = x;
}

bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) return true;
	else return false;
}

void Solve() {
	int max_num = 0;
	sort(Edge.begin(), Edge.end());

	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		if (SameParent(Edge[i].second.first, Edge[i].second.second) == false) {
			Union(Edge[i].second.first, Edge[i].second.second);
			Answer += Edge[i].first;
			
			if (max_num < Edge[i].first) {
				max_num = Edge[i].first;
			}
		}
	}

	cout << Answer - max_num;
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


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>

#define MAX 100001
using namespace std;

int N, M, max_cost;
vector<pair<int,int>> v[MAX];
int factory1, factory2;
bool Visit[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));

		max_cost = (max_cost > c) ? max_cost : c;
	}
	cin >> factory1 >> factory2;
}

bool BFS(int Cur_cost) {
	queue<int> q;
	q.push(factory1);
	Visit[factory1] = true;

	while (!q.empty()) {
		int cur_factory = q.front();
		q.pop();

		if (cur_factory == factory2) return true;

		for (int i = 0; i < v[cur_factory].size(); i++) {
			int next_factory = v[cur_factory][i].first;
			int next_factoryCost = v[cur_factory][i].second;

			if (Visit[next_factory] == false && Cur_cost <= next_factoryCost) {
				Visit[next_factory] = true;
				q.push(next_factory);
			}
		}
	}
	return false;
}

void Solve() {

	int left = 0;
	int right = max_cost;
	int mid = 0;

	while (left <= right) {
		memset(Visit, false, sizeof(Visit));
		mid = (left + right) / 2;
		if (BFS(mid) == true) left = mid + 1;
		else right = mid - 1;
	}
	cout << right;
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

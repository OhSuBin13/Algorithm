#include <iostream>
#include <vector>

#define MAX 501
#define INF 1e9
using namespace std;

int TC;
int N, M, W;
int d[MAX];
vector <pair<int, pair<int, int>>> edge;

void Init() {
	for (int i = 1; i < MAX; i++) {
		d[i] = INF;
	}
	edge.erase(edge.begin(), edge.end());
}

void Input() {
	Init();

	cin >> N >> M >> W;

	for (int i = 0; i < M; i++) {
		int s, e, t; cin >> s >> e >> t;
		edge.push_back({ t,{s,e} });
		edge.push_back({ t,{e,s} });
	}

	for (int i = 0; i < W; i++) {
		int s, e, t; cin >> s >> e >> t;
		edge.push_back({ (-1) * t,{s,e} });
	}
}

void Bellman_Ford() {
	d[1] = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int distance = edge[j].first;
			int from = edge[j].second.first;
			int to = edge[j].second.second;

			if (d[to] > d[from] + distance) {
				d[to] = d[from] + distance;
			}
		}
	}

	for (int i = 0; i < edge.size(); i++) {
		int distance = edge[i].first;
		int from = edge[i].second.first;
		int to = edge[i].second.second;

		if (d[to] > d[from] + distance) {
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
}


void Solve() {
	Bellman_Ford();
}


void Solution() {
	cin >> TC;

	while (TC--) {
		Input();
		Solve();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}

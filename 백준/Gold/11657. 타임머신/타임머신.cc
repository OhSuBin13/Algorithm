#include <iostream>
#include <vector>

#define MAX 501
#define INF 1e9
using namespace std;

int N, M;
long long int d[MAX];
vector<pair<int, pair<int, int>>> edges;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edges.push_back({ A,{B,C} });
	}

	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
}

bool Bellman_Ford(int start) {
	d[start] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int from = edges[j].first;
			int to = edges[j].second.first;
			int cost = edges[j].second.second;

			if (d[from] == INF) continue;

			if (d[to] > d[from] + cost) {
				d[to] = d[from] + cost;

				if (i == N) {
					return true;
				}
			}
		}
	}

	return false;
}

void Solve() {
	bool negativeCycle = Bellman_Ford(1);
	if (negativeCycle) {
		cout << "-1\n";
		return ;
	}

	for (int i = 2; i <= N; i++) {
		if (d[i] == INF) {
			cout << "-1\n";
		}
		else {
			cout << d[i] << "\n";
		}
	}
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

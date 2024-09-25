#include <iostream>
#include <vector>

#define MAX 401
#define INF 1e9
using namespace std;

int n, k, s;
int history[401][401];
vector<pair<int, int>> question;

void SetHistory() {
	for (int i = 1; i < 401; i++) {
		for (int j = 1; j < 401; j++) {
			history[i][j] = INF;
		}
	}
}

void Input() {
	SetHistory();
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;

		history[a][b] = 1;
		history[b][a] = -1;
	}

	cin >> s;

	for (int i = 0; i < s; i++) {
		int a, b; cin >> a >> b;

		question.push_back(make_pair(a, b));
	}
}

void Floyd_Warshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (history[i][k] != INF && history[k][j] != INF) {
					if (history[i][k] == 1 && history[k][j] == 1) {
						history[i][j] = 1;
						history[j][i] = -1;
					}
					else if (history[i][k] == -1 && history[k][j] == -1) {
						history[i][j] = -1;
						history[j][i] = 1;
					}
				}
			}
		}
	}
}

void Solve() {
	Floyd_Warshall();

	for (int i = 0; i < question.size(); i++) {
		int src = question[i].first;
		int dist = question[i].second;

		if (history[src][dist] == -1) {
			cout << "1" << "\n";
		}
		else if (history[src][dist] == 1) {
			cout << "-1" << "\n";
		}
		else cout << "0" << "\n";
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

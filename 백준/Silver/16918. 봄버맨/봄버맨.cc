#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define MAX 99999999
using namespace std;

int R, C, N;
vector<vector<pair<char,int>>> v;
int mX[4] = { -1,0,1,0 };
int mY[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void Input() {
	cin >> R >> C >> N;
	
	v.resize(R);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;
			if (c == 'O') v[i].push_back(make_pair(c, 3));
			else v[i].push_back(make_pair(c, 0));
		}
	}
}

void BFS() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (v[i][j].first == 'O' && v[i][j].second == 0) {
				q.push({i,j});
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		v[x][y] = make_pair('.', 0);

		for (int i = 0; i < 4; i++) {
			int nx = x + mX[i];
			int ny = y + mY[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

			v[nx][ny] = make_pair('.', 0);
		}
	}
}

void Bomber() {
	N--;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (v[i][j].first == 'O' && v[i][j].second > 0) {
				v[i][j].second--;
			}
		}
	}

	
	while(N > 0) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (v[i][j].first != 'O') {
					v[i][j] = make_pair('O', 3);
				}
				else {
					if (v[i][j].second > 0) v[i][j].second--;
				}
			}
		}
		N--;

		if (N == 0) break;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (v[i][j].first == 'O' && v[i][j].second > 0) {
					v[i][j].second--;
				}
			}
		}

		BFS();
		N--;
	}
}

void Solve() {
	Bomber();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << v[i][j].first;
		}
		cout << "\n";
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
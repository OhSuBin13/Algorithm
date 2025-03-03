#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<vector<int>> v;
queue<pair<int, int>> q;
bool visited[50][50];
int arr[50][50];
int mX[4] = { -1,1,0,0 };
int mY[4] = { 0,0,-1,1 };
queue<vector<pair<int, int>>> virus;
vector<pair<int, int>> virusPos;
int res = 999999;

void Input() {
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			v[i].push_back(num);
			if (num == 2) {
				virusPos.push_back(make_pair(i, j));
			}
		}
	}
}

void Solution() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int time = arr[x][y];
		visited[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + mX[i];
			int ny = y + mY[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || v[nx][ny] == 1 || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			arr[nx][ny] = time + 1;
			q.push(make_pair(nx, ny));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && v[i][j] != 1) {
				return;
			}
		}
	}
	int maxNum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maxNum < arr[i][j]) maxNum = arr[i][j];
		}
	}
	if (res > maxNum) res = maxNum;
}

void Backtracking(vector<pair<int, int>> v, int cnt, int pos) {
	if (cnt == M) {
		virus.push(v);
		return;
	}
	for (int i = pos; i < virusPos.size(); i++) {
		vector<pair<int, int>> tmp = v;
		tmp.push_back({ virusPos[i].first, virusPos[i].second });
		Backtracking(tmp, cnt + 1, i + 1);
	}
}

void Solve() {
	Input();
	vector<pair<int, int>> tmp;
	Backtracking(tmp, 0, 0);
	while (!virus.empty()) {
		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		vector<pair<int, int>> x;
		x = virus.front();
		for (int i = 0; i < M; i++) {
			q.push(make_pair(x[i].first, x[i].second));
			visited[x[i].first][x[i].second] = true;
		}
		virus.pop();


		Solution();
	}
	if (res != 999999) cout << res;
	else cout << -1;
}

int main() {
	Solve();
	return 0;
}
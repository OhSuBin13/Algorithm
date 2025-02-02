#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N, Q;
vector<vector<int>> ice;
queue<int> magicSqell;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int vectorSize;

void Input() {
	int num;
	cin >> N >> Q;
	vectorSize = pow(2, N);
	ice.resize(vectorSize);
	for (int i = 0; i < vectorSize; i++) {
		ice[i].resize(vectorSize);
	}

	for (int i = 0; i < ice.size(); i++) {
		for (int j = 0; j < ice[i].size(); j++) {
			cin >> ice[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		cin >> num;
		magicSqell.push(num);
	}
}

void spinEach90(int startX, int startY, double size) {
	double midX = startX + (size - 1) / 2;
	double midY = startY + (size - 1) / 2;

	vector<vector<int>> tmp;
	tmp.resize(size);
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i].resize(size);
	}

	for (int i = startX; i < startX + size; i++) {
		for (int j = startY; j < startY + size; j++) {
			double difX = midX - i;
			double difY = midY - j;

			int newX = midX - difY;
			int newY = midY + difX;
			tmp[newX - startX][newY - startY] = ice[i][j];
		}
	}

	for (int i = startX; i < startX + size; i++) {
		for (int j = startY; j < startY + size; j++) {
			ice[i][j] = tmp[i - startX][j - startY];
		}
	}
}

void spinAll90() {
	int L = magicSqell.front();
	magicSqell.pop();

	if (L == 0) return;

	int size = pow(2, L);
	for (int i = 0; i < ice.size(); i += size) {
		for (int j = 0; j < ice[i].size(); j += size) {
			spinEach90(i, j, size);
		}
	}
}

void Solution() {
	while (!magicSqell.empty()) {
		spinAll90();

		vector<vector<int>> tmp;

		tmp = ice;

		for (int i = 0; i < ice.size(); i ++) {
			for (int j = 0; j < ice[i].size(); j ++) {
				if (ice[i][j] == 0) continue;

				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= vectorSize || ny < 0 || ny >= vectorSize) continue;

					if (ice[nx][ny] > 0) {
						cnt++;
					}
				}
				if (cnt < 3) {
					tmp[i][j]--;
				}
			}
		}
		ice = tmp;
	}
	int sum = 0;
	int res = 0;

	for (int i = 0; i < ice.size(); i++) {
		for (int j = 0; j < ice[i].size(); j++) {
			sum += ice[i][j];
		}
	}
	queue<pair<int,int>> q;
	bool visited[64][64] = { false, };

	for (int i = 0; i < vectorSize; i++) {
		for (int j = 0; j < vectorSize; j++) {
			if (ice[i][j] != 0 && !visited[i][j]) {
				int continuousIce = 1;
				q.push({ i,j });
				visited[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (visited[nx][ny] || nx < 0 || nx >= vectorSize || ny < 0 || ny >= vectorSize || ice[nx][ny] == 0) continue;

						visited[nx][ny] = true;
						continuousIce++;
						q.push({ nx, ny });
					}
				}
				res = max(res, continuousIce);
			}
		}
	}
	cout << sum << "\n";
	cout << res;
	/*for (int i = 0; i < ice.size(); i++) {
		for (int j = 0; j < ice[i].size(); j++) {
			cout << ice[i][j] << " ";
		}
		cout << "\n";
	}*/
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Solve();
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 500
using namespace std;

struct rain
{
	int hp;
	int umbrella;
	int x, y;
	int move;
};

int N, H, D;
char arr[MAX][MAX];
int startX, startY, dstX, dstY;
int res = -1;
queue<rain> q;

int mX[4] = { -1, 0, 1, 0 };
int mY[4] = { 0, 1, 0, -1 };

void Input() {
	cin >> N >> H >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				startX = i;
				startY = j;
			}
			if (arr[i][j] == 'E') {
				dstX = i;
				dstY = j;
			}
		}
	}
}

void BFS() {
	rain r;
	r.x = startX;
	r.y = startY;
	r.hp = H;
	r.umbrella = 0;
	r.move = 0;

	q.push(r);

	vector<vector<int>> discovered(500, vector<int>(500, 0)); //[x][y] = 해당 위치의 (최대 체력 + 내구도)

	while (!q.empty()) {
		rain ra = q.front();

		q.pop();
		int x = ra.x;
		int y = ra.y;
		int h = ra.hp;
		int um = ra.umbrella;
		int mv = ra.move;

		if (h == 0) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + mX[i];
			int ny = y + mY[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			rain nr;
			nr.x = nx;
			nr.y = ny;
			nr.move = mv + 1;

			if (arr[nx][ny] == 'U') {
				nr.umbrella = D - 1;
				nr.hp = h;
			}
			else if (arr[nx][ny] == 'E') {
				res = mv + 1;
				return;
			}
			else {
				if (um == 0) {
					nr.umbrella = 0;
					nr.hp = h - 1;
				}
				else {
					nr.umbrella = um -1;
					nr.hp = h;
				}
			}

			if (nr.hp > 0 && discovered[nx][ny] < nr.hp + nr.umbrella) {
				discovered[nx][ny] = nr.hp + nr.umbrella;
				q.push(nr);
			}
		}
	}
}

void Solve() {
	BFS();
	cout << res;
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

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char MAP[8][8]; //빈 칸과 벽 표시 

//캐릭터가 움직일 수 있는 방향
int mX[9] = { -1,-1,-1,0,1,1,1,0,0 };
int mY[9] = { -1,0,1,1,1,0,-1,-1,0 };

void Input() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> MAP[i][j];
		}
	}
}

void BFS() {
	queue<pair<int, pair<int, int>>> q; //시간, x, y
	q.push(make_pair(0, make_pair(7, 0)));

	while (!q.empty()) {
		int time = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (x == 0 && y == 7) {
			cout << 1 << "\n";
			return;
		}

		for (int i = 0; i < 9; i++) {
			int nx = x + mX[i];
			int ny = y + mY[i];

			//이동범위가 MAP을 나간 경우
			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
			//이동한 곳이 #인 경우
			if (nx - time >= 0 && MAP[nx - time][ny] == '#') continue;
			//벽이 이동한 후 사람과 만난 경우
			if (nx - time + 1 >= 0 && MAP[nx - time - 1][ny] == '#') continue;

			q.push(make_pair(time + 1, make_pair(nx, ny)));
		}
	}
	cout << 0;
}

void Solve() {
	BFS();
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
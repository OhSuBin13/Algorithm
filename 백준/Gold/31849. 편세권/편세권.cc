#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

struct poi {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	vector<vector<int>> d(n + 1, vector<int>(m + 1));
	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, 0));
	vector<poi> room(r);
	vector<int> p(r);
	queue<poi> q;
	for (int i = 0; i < r; i++) cin >> room[i].x >> room[i].y >> p[i];
	while (c--) {
		int xx, yy;
		cin >> xx >> yy;
		q.push({ xx,yy });
		d[xx][yy] = 0;
		vis[xx][yy] = 1;
	}
	int ans = 200000;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };
	while (!q.empty()) {
		poi now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (n < nx || nx < 1 || m < ny || ny < 1) continue;
			if (vis[nx][ny]) continue;
			d[nx][ny] = d[now.x][now.y] + 1;
			q.push({ nx, ny });
			vis[nx][ny] = 1;
		}
	}
	for (int i = 0; i < r; i++) {
		int xx = room[i].x;
		int yy = room[i].y;
		ans = min(ans, d[xx][yy] * p[i]);
	}
	cout << ans;
	return 0;
}
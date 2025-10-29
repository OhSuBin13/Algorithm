#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

int farm[100][100]; // Farm grid
bool visited[100][100]; // Visited cells tracker
int mx[4] = { 0, 0, 1, -1 }; // Directions for x-axis movement
int my[4] = { 1, -1, 0, 0 }; // Directions for y-axis movement

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int height = 0;
	int N;
	cin >> N; // Size of the farm

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> farm[i][j];
			if (height < farm[i][j]) height = farm[i][j];
		}
	}


	int ans = 1; // Size of the largest component

	for (int k = 1; k <= height; k++) {
		memset(visited, false, sizeof(visited));
		int count = 0; // Number of connected components
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (farm[i][j] > k && !visited[i][j]) {
					count++;
					queue<pii> q;
					q.push({ i, j });
					visited[i][j] = true;
					while (!q.empty()) {
						pii cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + mx[dir];
							int ny = cur.second + my[dir];
							if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
							if (farm[nx][ny] > k && !visited[nx][ny]) {
								visited[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}
				}
			}
		}
		if (ans < count) ans = count;
	}
	cout << ans;
	return 0;
}
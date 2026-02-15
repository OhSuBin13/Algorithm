#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> lamp;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		lamp.push_back(num);
	}
	int dist = lamp[0];
	for (int i = 1; i < lamp.size(); i++) {
		int curDist = lamp[i] - lamp[i - 1];
		if (curDist > dist) {
			dist = curDist;
		}
	}
	int curDist = N - lamp[M - 1];
	if (curDist > dist) {
		dist = curDist;
	}
	if (dist == lamp[0] || dist == N - lamp[M - 1]) cout << dist;
	else if (dist % 2 == 0) {
		if (dist / 2 > lamp[0] && dist / 2 > N - lamp[M - 1])
			cout << dist / 2;
		else cout << max(lamp[0], N - lamp[M - 1]);
	}
	else if (dist % 2 == 1) {
		if (dist / 2 + 1 > lamp[0] && dist / 2 + 1 > N - lamp[M - 1])
			cout << dist / 2 + 1;
		else cout << max(lamp[0], N - lamp[M - 1]);
	}
	return 0;
}
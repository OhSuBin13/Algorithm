#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;


	int point[100001]; // 점들의 x좌표 배열
	vector<pair<int, int>> line(M); // 선분들의 start, end 좌표
	
	for (int i = 0; i < N; i++) {
		cin >> point[i];
	}
	
	sort(point, point + N);

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout << upper_bound(point, point + N, y) - lower_bound(point, point + N, x) << "\n";
	}
			
	return 0;
}
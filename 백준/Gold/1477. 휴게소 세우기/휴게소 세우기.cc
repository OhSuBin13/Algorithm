#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int N, M, L; //현재 휴게소 개수, 더 지을 휴게소 개수, 고속도로 길이
	vector<int> pos; //휴게소 위치
	int cnt, high, low, mid, ans = 0;

	cin >> N >> M >> L;
	pos.push_back(0);
	pos.push_back(L);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pos.push_back(num);
	}

	sort(pos.begin(), pos.end());

	high = L;
	low = 1;

	while (high >= low) {
		mid = (high + low) / 2;

		cnt = 0;
		for (int i = 1; i < pos.size(); i++) {
			int dist = pos[i] - pos[i - 1];
			cnt += dist / mid;
			if (dist % mid == 0) {
				cnt--;
			}
		}

		if (cnt > M) {
			low = mid + 1;
		}
		else {
			ans = mid;
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}
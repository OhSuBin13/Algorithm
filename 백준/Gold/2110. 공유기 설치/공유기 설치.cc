#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, C; // 집의 개수, 공유기의 개수
	vector<long long int> studio;

	cin >> N >> C;
	studio.resize(N); // 집의 좌표
	for (int i = 0; i < N; i++) {
		cin >> studio[i];
	}

	sort(studio.begin(), studio.end());

	long long int high = studio[N - 1] - studio[0];
	long long int low = 1;
	long long int mid;
	long long int ans = 0;
	int router, st;

	while (high >= low) {
		router = 1;
		mid = (high + low) / 2;
		st = 0;
		
		for (int i = 1; i < N; i++) {
			if (studio[i] - studio[st] >= mid) {
				st = i;
				router++;
			}
		}

		if (router >= C) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}

	cout << ans;

	return 0;
}
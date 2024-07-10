#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, M; // 입국 심사대, 인원 수
	vector<long long int> t; // 심사 시간
	cin >> N >> M;
	t.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}

	sort(t.begin(), t.end());

	unsigned long long high = M * t[0];
	// 심사 시간이 제일 적은 데스크에 모든 사람이 검사 받는 경우를 최대 값으로 잡아줌
	unsigned long long low = 1;
	unsigned long long mid;
	unsigned long long ans = 0;
	unsigned long long people;

	while (high >= low) {
		people = 0;
		mid = (high + low) / 2;
		for (int i = 0; i < N; i++) {
			people += mid / t[i];
		}

		if (people >= M) {
			if (ans > mid || ans == 0) {
				ans = mid;
			}
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << ans;

	return 0;
}
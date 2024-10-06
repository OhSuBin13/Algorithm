#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<long long int> v;
long long int ans[3];
long long int ret = 1e18;

void Input() {
	cin >> N;
	int a;

	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
}

void Solve() {
	for (int i = 0; i <= N - 3; i++) {
		int st = i + 1;
		int end = N - 1;
		
		while(st < end) {
			long long int num = v[i] + v[st] + v[end];

			if (abs(num) < ret) {
				ret = abs(num);
				ans[0] = v[i];
				ans[1] = v[st];
				ans[2] = v[end];
			}
			if (num < 0) st++;
			else end--;
		}
	}
}


void Solution() {
	Input();
	Solve();
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}

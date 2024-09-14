#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int N, d, k, c;
vector<int> v;
int res = 0;
unordered_map<int, int> m;

void Input() {
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
}

void TwoPointer() {
	int start = 0;
	int end = k - 1;
	int cnt = 0;

	for (int i = start; i <= end; i++) {
		m[v[i]]++;
		if (m[v[i]] == 1) cnt++;
	}

	if (res < cnt) {
		if (m[c] == 0) res = cnt + 1;
		else res = cnt;
	}
	//cout << start << " " << res << "\n";

	while (start != N) {
		m[v[start]]--;
		if (m[v[start]] == 0) cnt--;
		start++;

		end++;
		if (end >= N) end %= N;
		m[v[end]]++;
		if (m[v[end]] == 1) cnt++;

		if (m[c] == 0) res = (res < cnt + 1) ? cnt + 1 : res;
		else res = (res < cnt) ? cnt : res;

		//cout << start << " " << res << "\n";
	}
}

void Solve() {
	TwoPointer();
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
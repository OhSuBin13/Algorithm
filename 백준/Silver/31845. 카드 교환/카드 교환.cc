#include <iostream>	
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int ans = 0;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
}

void Solution() {
	for (int i = 0; i < M; i++) {
		int num;
		if (!v.empty()) num = v[v.size() - 1];
		else break;
		if (num < 0) break;
		ans += num;
		v.pop_back();
		if (!v.empty()) v.erase(v.begin());
	}
	cout << ans;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	Solve();
	return 0;
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, K;
vector<int> v;
map<int, int> m;
int res = 0;

void Input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
}

void TwoPointer() {
	int start = 0;
	int end = 0;

	int length = 0;

	while (end != v.size()) {
		m[v[end]]++;
		//cout << end << " " << m[v[end]] << "\n";
		while (m[v[end]] > K) {
			m[v[start]]--;
			start++;
		}
		
		length = end - start + 1;
		res = (res < length) ? length : res;
		end++;
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
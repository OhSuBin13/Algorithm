#include <iostream>
#include <vector>

using namespace std;

int N, W;
vector<vector<int>> tree;
int cnt = 0;
double ans;

void Input() {
	cin >> N >> W;
	tree.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
}

void Travel() {
	for (int i = 2; i <= N; i++) {
		if (tree[i].size() == 1) cnt++;
	}
}

void Solve() {
	Travel();
	ans = (double)W / cnt;
}

void Solution() {
	Input();
	Solve();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout.precision(6);
	cout << fixed;

	Solution();

	cout  << ans << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), compare);
	int ans = v[N-1].second;
	int max_height = v[N-1].second;
	int max_width = v[N - 1].first;

	for (int i = N - 1; i >= 0; i--) {
		if (max_height < v[i].second) {
			ans += max_height* (max_width - v[i].first) + v[i].second - max_height;
			max_height = v[i].second;
			max_width = v[i].first;
		}
	}
	int max_height2 = v[0].second;
	int max_width2 = v[0].first;
	for (int i = 0; i <= N - 1; i++) {
		if (max_height2 <= v[i].second) {
			ans += max_height2 * (v[i].first - max_width2);
			max_height2 = v[i].second;
			max_width2 = v[i].first;
		}
	}
	cout << ans;
	return 0;
}
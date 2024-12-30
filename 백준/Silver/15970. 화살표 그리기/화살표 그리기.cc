#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	vector<vector<int>> v;
	int N;

	cin >> N;
	v.resize(N + 1);

	for (int i = 0; i < N; i++) {
		int pos, color;
		cin >> pos >> color;
		v[color].push_back(pos);
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	int res = 0;

	for (int i = 1; i <= N; i++) {
		if (v[i].size() == 1) continue;

		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0) {
				res += v[i][j + 1] - v[i][j];
				continue;
			}
			else if (j == v[i].size() - 1) {
				res += v[i][j] - v[i][j - 1];
				continue;
			}
			res += v[i][j+1] - v[i][j] < v[i][j] - v[i][j - 1] ? v[i][j + 1] - v[i][j] : v[i][j] - v[i][j - 1];
		}
	}

	cout << res;
}
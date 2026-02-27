#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int p, m, l;
	string n;
	vector<pair<int, int>> v; //레벨, 인원
	vector<vector<pair<int, string>>> v2; //각각 레벨, 아이디
	cin >> p >> m;
	for (int i = 0; i < p; i++) {
		cin >> l >> n;
		if (i == 0) {
			v.push_back({ l, 1 });
			vector<pair<int, string>> tmp;
			tmp.push_back({ l, n });
			v2.push_back(tmp);
			continue;
		}
		for (int j = 0; j < v.size(); j++) {
			int level = v[j].first;
			int number = v[j].second;
			if (level - 10 <= l && l <= level + 10 && number < m) {
				v[j].second++;
				v2[j].push_back({ l, n });
				break;
			}
			if (j == v.size() - 1) {
				v.push_back({ l, 1 });
				vector<pair<int, string>> tmp;
				tmp.push_back({ l, n });
				v2.push_back(tmp);
				break;
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == m) cout << "Started!" << "\n";
		else cout << "Waiting!" << "\n";

		sort(v2[i].begin(), v2[i].end(), compare);
		for (int j = 0; j < v2[i].size(); j++) {
			cout << v2[i][j].first << " " << v2[i][j].second << "\n";
		}
	}

	return 0;
}
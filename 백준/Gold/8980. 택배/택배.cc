#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, M;
typedef pair<pair<int, int>, int> p;
vector<p> v;

bool cmp(p a, p b) {
	return a.first.second < b.first.second;
}

void Input() {
	cin >> N >> C;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({{a,b}, c });
	}
	sort(v.begin(), v.end(), cmp);
}

int main() {
	Input();
	vector<int> truck(N);
	int size = v.size();
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int start = v[i].first.first - 1;
		int end = v[i].first.second - 1;
		int box = v[i].second;
		int temp = 0;
		int cnt = 0;

		for (int j = start; j < end; j++) {
			temp = max(temp, truck[j]);
		}
		if (temp + box <= C) cnt = box;
		else cnt = C - temp;

		for (int j = start; j < end; j++) {
			truck[j] += cnt;
		}
		ans += cnt;
	}

	cout << ans;

	return 0;
}
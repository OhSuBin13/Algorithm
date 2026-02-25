#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
인덱스 : id
1. 점수 총합 내림차순 (각 문제 최고점)
2. 제출 횟수
3. 최종 제출 시간

return : rank (앞 선 팀 개수 + 1)
*/
struct Rank {
	int id = 0;
	vector<int> score;
	int submit = 0;
	int lastTime = 0;
	int sum = 0;
};

bool compare(const Rank& r1, const Rank& r2) {
	if (r1.sum == r2.sum) {
		if (r1.submit == r2.submit) return r1.lastTime < r2.lastTime;
		else return r1.submit < r2.submit;
	}
	return r1.sum > r2.sum;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	int n, k, t, m; // 팀 개수, 문제 개수, 팀 ID, 로그 엔트리 개수
	while (T--) {
		vector<Rank> v;
		cin >> n >> k >> t >> m;
		v.resize(n + 1);
		int time = 1;

		v[0].sum = -1;
		for (int i = 1; i <= n; i++) {
			v[i].id = i;
			v[i].score.resize(k + 1);
		}

		for (int i = 0; i < m; i++) {
			int id, pb, sc;
			cin >> id >> pb >> sc;
			if (v[id].score[pb] < sc) {
				v[id].sum += sc - v[id].score[pb];
				v[id].score[pb] = sc;
			}
			v[id].submit += 1;
			v[id].lastTime = time++;
		}
		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < v.size(); i++) {
			if (v[i].id == t) {
				cout << i + 1 << "\n";
				break;
			}
		}
	}

	return 0;
}
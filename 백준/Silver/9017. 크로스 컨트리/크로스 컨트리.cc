#include <iostream>
#include <cstring>
#include <map>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	int arr[1001];
	int count[201] = { 0, };
	map<int, pair<int, int>> score; // team, {score, people}
	map<int, pair<int, int>> secondScore; // team, {score, people}


	while (T--) {
		int N; cin >> N;
		score.clear();
		secondScore.clear();
		memset(count, 0, sizeof(count));
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			count[arr[i]]++;
		}
		int rank = 1;
		for (int i = 0; i < N; i++) {
			if (count[arr[i]] < 6) continue;
			int curScore = score[arr[i]].first;
			int curPeople = score[arr[i]].second;
			if (curPeople <= 3) score[arr[i]] = make_pair(curScore + rank, curPeople + 1);
			if (curPeople == 4 && secondScore[arr[i]].second == 0) {
				secondScore[arr[i]] = make_pair(curScore + rank, curPeople + 1);
			}
			rank++;
		}

		int minScore = 1000000;
		int maxPos = 0;
		for (int i = 1; i <= 200; i++) {
			if (count[i] < 6) continue;
			int curScore = score[i].first;
			if (minScore > curScore) {
				minScore = curScore;
				maxPos = i;
			}
			else if (minScore == curScore) {
				int firstS = secondScore[maxPos].first;
				int secondS = secondScore[i].first;
				if (firstS > secondS) {
					maxPos = i;
				}
			}
		}
		cout << maxPos << "\n";
	}

	return 0;
}
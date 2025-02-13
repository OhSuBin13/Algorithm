#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, answer = 1;
vector<pair<int, int>> lecture;
priority_queue<int, vector<int>, greater<int>> lastTime;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		lecture.push_back({ b,c });
	}
	sort(lecture.begin(), lecture.end());

	for (int i = 0; i < lecture.size(); i++) {
		int startTime = lecture[i].first;
		int endTime = lecture[i].second;

		if (lastTime.empty()) {
			lastTime.push(endTime);
		}
		else {
			if (lastTime.top() > startTime) {
				answer++;
			}
			else {
				lastTime.pop();
			}
			lastTime.push(endTime);
		}
	}
	cout << answer;
	return 0;
}

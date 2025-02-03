#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[50];
int N;
int totalLength = 0;
vector<vector<int>> line;
priority_queue<pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

int find(int x) {
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

void unionSets(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

int lowerCaseToInt(char lowerInput) {
	int changeNum = (int)lowerInput - 96;
	return changeNum;
}

int upperCaseToInt(char upperInput) {
	int changeNum = (int)upperInput - 38;
	return changeNum;
}

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string lineInput;
		cin >> lineInput;
		for (int j = 0; j < lineInput.size(); j++) {
			int changeNum = (int)lineInput[j];
			int resultNum;
			if (lineInput[j] == 0) {
				q.push({ 0,{i,j} });
			}
			else if (changeNum >= 97 && changeNum <= 122) {
				resultNum = lowerCaseToInt(lineInput[j]);
				q.push({ resultNum,{i,j}});
				totalLength += resultNum;
			}
			else if (changeNum >= 65 && changeNum <= 90) {
				resultNum = upperCaseToInt(lineInput[j]);
				q.push({ resultNum,{i,j}});
				totalLength += resultNum;
			}
		}
	}
}

void Solution() {
	int minimumLine = 0;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	while (!q.empty()) {
		int lineLength = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		if (find(x) != find(y)) {
			unionSets(x, y);
			minimumLine += lineLength;
		}
	}

	bool flag = true;
	for (int i = 0; i < N - 1; i++) {
		if (find(i) != find(i+1)) {
			flag = false;
			break;
		}
	}

	if (!flag) cout << "-1";
	else cout << totalLength - minimumLine;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	Solve();
	return 0;
}
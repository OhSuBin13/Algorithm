#include <iostream>
#include <vector>
#include <deque>

#define MAX 201
using namespace std;

int N, K;
deque<pair<int,int>> durability; //내구도, 로봇 우선순위(0 : 로봇 빈칸 1 : 로봇 존재)
int level = 0;
int checkSum = 0;

void Input() {
	cin >> N >> K;
	for (int i = 0; i < 2*N; i++) {
		int n;
		cin >> n;
		durability.push_back(make_pair(n,0));
	}
}

void Check() {
	for (int i = 0; i < durability.size(); i++) {
		cout << durability[i].first << " ";
	}
	cout << "\n";
}

void ClearLast() {
	durability[N - 1].second = 0;
}

void StepOne() {
	durability.push_front(durability.back());
	durability.pop_back();

	ClearLast();
}

void StepTwo() {
	for (int i = durability.size() - 1; i >= 1; i--) {
		int robot = durability[i].second;
		int nextDurability = durability[(i + 1) % (2 * N)].first;
		int nextRobot = durability[(i + 1) % (2 * N)].second;

		if (nextRobot == 1) continue;
		if (robot == 0) continue;
		if (nextDurability == 0) continue;

		durability[i].second = 0;
		durability[(i + 1) % (2 * N)].second = 1;

		durability[(i + 1) % (2 * N)].first--;
	}

	ClearLast();
}

void StepThree() {
	if (durability[0].first != 0) {
		durability[0].first--;
		durability[0].second = 1;
	}
	ClearLast();

}

void StepFour() {
	checkSum = 0;

	for (int i = 0; i < durability.size(); i++) {
		if (durability[i].first == 0) checkSum++;
	}
	
	ClearLast();
}

void Solve() {
	while (1) {
		StepOne();
		StepTwo();
		StepThree();
		StepFour();
		level++;

		if (checkSum >= K) break;
	}

	cout << level;
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
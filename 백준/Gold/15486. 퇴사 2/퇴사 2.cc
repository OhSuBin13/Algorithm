#include <iostream>
#include <vector>

#define MAX 1500002
using namespace std;

int N, Answer;
vector<pair<int,int>> counsel; // time, pay
int DP[MAX];

int Bigger(int A, int B) {
	if (A > B) return A;
	return B;
}

void Input() {
	cin >> N;
	counsel.resize(N + 2);

	int T, P;
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		counsel[i] = make_pair(T, P);
	}
}

void Solve() {
	int Current_Max = 0;
	for (int i = 1; i <= N + 1; i++) {
		Current_Max = Bigger(Current_Max, DP[i]);
		if (i + counsel[i].first > N + 1) continue;

		DP[i + counsel[i].first] = Bigger(Current_Max + counsel[i].second, DP[i + counsel[i].first]);
	}
	Answer = Current_Max;
}


void Solution() {
	Input();
	Solve();
	cout << Answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}

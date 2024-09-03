#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cmath>
#define MAX 5005
using namespace std;

int N, K, Q, M; //학생 수, 졸고 있는 학생 수, 출석 코드 받을 학생 수, 주어질 구간의 수
int Sleep[MAX];
int AttendCode[MAX];
int S, E;
int Check[MAX] = { 0, };
int PrefixSum[MAX] = { 0, };

void Input() {
	cin >> N >> K >> Q >> M;

	for (int i = 0; i < K; i++) {
		cin >> Sleep[i];
	}

	for (int i = 0; i < Q; i++) {
		cin >> AttendCode[i];
	}
}

void Solve() {
	sort(AttendCode, AttendCode + Q);

	for (int i = 0; i < K; i++) {
		Check[Sleep[i]] = -1;
	}

	for (int i = 0; i < Q; i++) {
		if (Check[AttendCode[i]] == -1) continue;

		int tmp = AttendCode[i];
		while (tmp <= N + 2) {
			if (Check[tmp] != -1) {
				Check[tmp] = 1;
			}
			tmp += AttendCode[i];
		}
	}

	for (int i = 2; i <= N + 2; i++) {
		if (Check[i] != 1) {
			PrefixSum[i] = PrefixSum[i - 1] + 1;
		}
		else PrefixSum[i] = PrefixSum[i - 1];
	}
}

void Solution() {
	Input();
	Solve();
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		cout << PrefixSum[E] - PrefixSum[S-1] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solution();

	return 0;
}


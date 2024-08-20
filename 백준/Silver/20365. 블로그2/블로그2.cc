#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 500000
using namespace std;

int N;
char arr[MAX];
int res = 0;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void Solve() {
	int B = 0, R = 0;
	bool continueB = false;
	bool continueR = false;


	for (int i = 0; i < N; i++) {
		if (i == 0) {
			if (arr[i] == 'B') continueB = true;
			else continueR = true;
		}

		if (continueB && arr[i] == 'R') {
			continueB = false;
			continueR = true;
			B++;
		}
		else if (continueR && arr[i] == 'B') {
			continueR = false;
			continueB = true;
			R++;
		}
		
		if (i == N - 1) {
			if (continueR) R++;
			else B++;
		}
	}

	if (B >= R) {
		int firstB, lastB;
		for (int i = 0; i < N; i++) {
			if (arr[i] == 'B') {
				firstB = i;
				break;
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			if (arr[i] == 'B') {
				lastB = i;
				break;
			}
		}
		//cout << "firstB" << firstB << " " << "lastB" << lastB << "\n";

		res++;

		for (int i = firstB; i <= lastB; i++) {
			if (arr[i] == 'R' && arr[i - 1] == 'B') {
				res++;
				//cout << "i : " << i << "res : " << res << "\n";
			}
		}

		if (firstB != 0) res++;
		if (lastB != N - 1) res++;

	}
	else {
		int firstR, lastR;
		for (int i = 0; i < N; i++) {
			if (arr[i] == 'R') {
				firstR = i;
				break;
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			if (arr[i] == 'R') {
				lastR = i;
				break;
			}
		}

		res++;

		for (int i = firstR; i <= lastR; i++) {
			if (arr[i] == 'B' && arr[i - 1] == 'R') {
				//cout << "i : " << i << "res : " << res << "\n";
				res++;
			}
		}
		if (firstR != 0) res++;
		if (lastR != N - 1) res++;
	}
	cout << res;
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
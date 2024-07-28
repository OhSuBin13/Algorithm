#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

#define MAX 11
using namespace std;

int arr[5][5];
bool bingo[5][5] = { false, };
bool bing =false;
int res = 0;

void Input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
}

void CheckBingo() {
	int res = 0;

	for (int i = 0; i < 5; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] == true) cnt++;
		}
		if (cnt == 5) res++;
	}
	
	for (int j = 0; j < 5; j++) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (bingo[i][j] == true) cnt++;
		}
		if (cnt == 5) res++;
	}

	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][i] == true) cnt++;
	}
	if (cnt == 5) res++;

	int cnt2 = 0;
	for (int i = 0; i < 5; i++) {
		if (bingo[i][4-i] == true) cnt2++;
	}
	if (cnt2 == 5) res++;

	if(res >= 3) bing = true;
}

void Check(int num) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (num == arr[i][j]) {
				bingo[i][j] = true;
				res++;
				CheckBingo();
				if (bing) {
					cout << res;
				}
			}
		}
	}
}

void Solve() {
	int num;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			Check(num);
			if (bing) return;
		}
	}
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
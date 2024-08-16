#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

#define MAX 99999999
using namespace std;

int N;
vector<string> v;

void Input() {
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;
		v[i] = cmd;
	}
}

bool CheckZero(int srcX, int srcY, int dstX, int dstY) {
	for (int i = srcX; i <= dstX; i++) {
		for (int j = srcY; j <= dstY; j++) {
			if (v[i][j] == '1') return false;
		}
	}
	return true;
}

bool CheckOne(int srcX, int srcY, int dstX, int dstY) {
	for (int i = srcX; i <= dstX; i++) {
		for (int j = srcY; j <= dstY; j++) {
			if (v[i][j] == '0') return false;
		}
	}
	return true;
}

string Display(int srcX, int srcY, int dstX, int dstY) {
	//cout << srcX << " " << srcY << " " << dstX << " " << dstY << "\n";
	int midX = (srcX + dstX) / 2;
	int midY = (srcY + dstY) / 2;

	if (CheckZero(srcX, srcY, dstX, dstY)) return "0";
	else if (CheckOne(srcX, srcY, dstX, dstY)) return "1";
	else return ("(" + Display(srcX, srcY, midX, midY)
		+ Display(srcX, midY + 1, midX, dstY)
		+ Display(midX + 1, srcY, dstX, midY)
		+ Display(midX + 1, midY + 1, dstX, dstY)
+ ")");
}

/* + Display(srcX, dstY / 2 + 1, dstX / 2, dstY)
+ Display(dstX / 2 + 1, srcY, dstX, dstY / 2)
+ Display(dstX / 2 + 1, dstY / 2 + 1, dstX, dstY)*/

void Solve() {
	cout << Display(0, 0, N - 1, N - 1);
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
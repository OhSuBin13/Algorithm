#include <iostream>	
using namespace std;

int robotPos, boxPos, dstPos;

void Input() {
	for (int i = 0; i < 10; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == '@') {
			robotPos = i;
		}
		else if (cmd == '#') {
			boxPos = i;
		}
		else if (cmd == '!') {
			dstPos = i;
		}
	}
}

void Solution() {
	if (!((robotPos < boxPos && boxPos < dstPos) || (dstPos < boxPos && boxPos < robotPos))) {
		cout << -1;
		return;
	}
	if (dstPos > robotPos) cout << dstPos - robotPos - 1;
	else cout << robotPos - dstPos - 1;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	Solve();
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 100
using namespace std;

char startLeft;
char startRight;
string s;
int res = 0;
int leftX, leftY;
int rightX, rightY;

char arrLeft[3][6] = {
	{'q', 'w', 'e', 'r', 't'},
	{'a', 's', 'd', 'f', 'g'},
	{'z','x', 'c', 'v'}
};

char arrRight[3][6] = {
	{' ','y','u','i','o','p'},
	{' ','h','j','k','l'},
	{'b', 'n','m'}
};

void Input() {
	cin >> startLeft >> startRight;
	cin >> s;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			if (arrLeft[i][j] == startLeft) {
				leftX = j;
				leftY = i;
				//cout << "leftX" << leftX << " " << leftY << "\n";
			}
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			if (arrRight[i][j] == startRight) {
				rightX = j;
				rightY = i;
				//cout << "rightX" << rightX << " " << rightY << "\n";
			}
		}
	}
	
}

void Solve() {

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 6; k++) {
				if (arrLeft[j][k] == s[i]) {
					res += abs(leftX - k) + abs(leftY - j);
					res++;
					leftX = k, leftY = j;
				}
				else if (arrRight[j][k] == s[i]) {
					res += abs(rightX - k) + abs(rightY - j);
					res++;
					rightX = k, rightY = j;
				}
			}
		}
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
#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char arr[1001][1001];
	int heartX = 0, heartY = 0, N;
	int lArm = 0, rArm = 0, twist = 0, lLeg = 0 , rLeg = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (!heartX && !heartY && arr[i][j] == '*') {
				heartX = i + 1;
				heartY = j;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == heartX && j < heartY && !lArm && arr[i][j] == '*') {
				lArm = heartY - j;
			}
			else if (i == heartX && j > heartY && arr[i][j] == '*') {
				rArm = j - heartY;
			}
			else if (i > heartX && j == heartY && arr[i][j] == '*') {
				twist = i - heartX;
			}
			else if (i > heartX && j == heartY - 1 && arr[i][j] == '*') {
				lLeg = i - (heartX + twist);
			}
			else if (i > heartX && j == heartY + 1 && arr[i][j] == '*') {
				rLeg = i - (heartX + twist);
			}
		}
	}
	cout << heartX << " " << heartY << "\n";
	cout << lArm << " " << rArm << " " << twist << " " << lLeg << " " << rLeg;
}
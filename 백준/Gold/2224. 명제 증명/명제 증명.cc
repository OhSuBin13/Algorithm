#include <iostream>
#include <string>

#define MAX 52
using namespace std;

int N;
int arr[MAX][MAX]; // 0~25 : A_Z(65~90) 26~51 : a_z(97~122)
int res = 0;

int CharToInt(char letter) {
	int num;

	if ((int)letter >= 65 && (int)letter <= 90) {
		num = (int)letter - 65;
	}
	else {
		num = (int)letter - 71;
	}

	return num;
}

void Input() {
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string cmd;
		char a, b;

		getline(cin, cmd);

		if (cmd.size() == 6) {
			a = cmd[0], b = cmd[5];

			int c, d;
			c = CharToInt(a);
			d = CharToInt(b);

			arr[c][d] = 1;
		}
	}
}

char IntToChar(int num) {
	char letter;

	if (num >= 0 && num <= 25) {
		letter = (char)(num + 65);
	}
	else {
		letter = (char)(num + 71);
	}

	return letter;
}

void Check() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (arr[i][j] == 1 && i != j) {
				res++;
			}
		}
	}
	cout << res << "\n";

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (arr[i][j] == 1 && i != j) {
				cout << IntToChar(i) << " => " << IntToChar(j) << "\n";
			}
		}
	}
}

void Floyd_Warshall() {
	for (int k = 0; k < MAX; k++) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (i == j) continue;

				if (arr[i][k] == 1 && arr[k][j] == 1) {
					arr[i][j] = 1;
				}
			}
		}
	}
}

void Solve() {
	Floyd_Warshall();
	Check();
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

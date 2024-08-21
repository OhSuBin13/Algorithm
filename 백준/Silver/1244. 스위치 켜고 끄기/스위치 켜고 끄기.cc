#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX 101
using namespace std;

int swit;
int state[MAX];
int student; //학생 수
queue<pair<int, int>> person; //성별, 받은 수

void Input() {
	cin >> swit;

	for (int i = 1; i <= swit; i++) {
		cin >> state[i];
	}

	cin >> student;
	for (int i = 0; i < student; i++) {
		int a, b;
		cin >> a >> b;

		person.push({ a,b });
	}
}

void Solve() {
	while (!person.empty()) {
		int sex = person.front().first;
		int num = person.front().second;
		person.pop();

		if (sex == 1) {
			for (int i = num; i <= swit; i += num) {
				state[i] = (state[i] + 1) % 2;
			}
		}
		else if (sex == 2) {
			state[num] = (state[num] + 1) % 2;

			for (int i = 1; i <= swit; i++) {
				if (num - i < 1 || num + i > swit) break;

				if (state[num - i] == state[num + i]) {
					state[num - i] = (state[num - i] + 1) % 2;
					state[num + i] = (state[num + i] + 1) % 2;
				}
				else break;
			}
		}
	}

	for (int i = 1; i <= swit; i++) {
		cout << state[i] << " ";
		if (i % 20 == 0) cout << "\n";
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
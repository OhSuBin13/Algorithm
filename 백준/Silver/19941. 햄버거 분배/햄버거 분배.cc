#include <iostream>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, ans = 0;
	string input;
	queue<int> burgerPos, humanPos;
	cin >> N >> K;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'H') humanPos.push(i);
		else burgerPos.push(i);
	}
	
	while (!humanPos.empty()) {
		int curHumanPos = humanPos.front();
		humanPos.pop();
		while (!burgerPos.empty()) {
			int curBurgerPos = burgerPos.front();
			if (abs(curHumanPos - curBurgerPos) <= K) {
				ans++;
				burgerPos.pop();
				break;
			}
			else if (curBurgerPos > curHumanPos) {
				break;
			}
			else burgerPos.pop();
		}
	}
	cout << ans;
	return 0;
}
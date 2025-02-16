#include <iostream>
#include <cstring>
using namespace std;

bool visited[11];
int arr[11][11];
int res = 0;

void Backtracking(int n, int ability, int player) {
	if (n == 11) {
		res = max(ability, res);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (!visited[i] && arr[player][i] != 0) {
			visited[i] = true;
			int newAbility = ability + arr[player][i];
			Backtracking(n + 1, newAbility, player + 1);
			visited[i] = false;
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(visited, false, sizeof(visited));
		res = 0;
		
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> arr[i][j];
			}
		}

		Backtracking(0, 0, 0);
		cout << res << "\n";
	}
}
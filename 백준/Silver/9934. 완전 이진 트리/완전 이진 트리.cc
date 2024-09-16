#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K;
vector<int> building;
vector<int> depth[11];

void Input() {
	cin >> K;
	for (int i = 0; i < pow(2,K) - 1; i++) {
		int a;
		cin >> a;
		building.push_back(a);
	}
}

void Inorder(int start, int end, int level) {
	int mid = (start + end) / 2;
	depth[level].push_back(building[mid]);

	if (start == end) return;

	Inorder(start, mid - 1, level + 1);
	Inorder(mid + 1, end, level + 1);
}

void Solve() {
	Inorder(0, building.size()-1, 1);

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < depth[i].size(); j++) {
			cout << depth[i][j] << " ";
		}
		cout << "\n";
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
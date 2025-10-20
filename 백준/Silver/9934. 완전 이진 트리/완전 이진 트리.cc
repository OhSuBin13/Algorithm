#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int node[1024] = { 0, };
vector<vector<int>> v(11);

void Inorder(int start, int end, int height) {
	if (start > end) return;
	int mid = (start + end) / 2;
	v[height].push_back(node[mid]);
	Inorder(start, mid - 1, height + 1);
	Inorder(mid + 1, end, height + 1);
}

int main() {
	int k, num;
	cin >> k;
	int maxNum = pow(2, k) - 1;
	for (int i = 1; i <= maxNum; i++) {
		cin >> node[i];
	}
	Inorder(1, maxNum, 1);
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
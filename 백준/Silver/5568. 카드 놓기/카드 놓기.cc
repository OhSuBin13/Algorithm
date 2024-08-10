#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

#define MAX 99999999
using namespace std;

int n, k;
int arr[10];
int res = 0;
bool visited[10];
vector<int> v;

void Input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void Backtracking(int cnt, int num) {
	if (cnt == k) {
		v.push_back(num);
		//cout << num << " ";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		int pos = 0;
		int tmp = arr[i];
		while (1) {
			if (tmp == 0) break;
			else {
				tmp /= 10;
				pos++;
			}
		}
		Backtracking(cnt + 1, num * pow(10, pos) + arr[i]);
		visited[i] = false;
	}
	
}

void Solve() {
	Backtracking(0, 0);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (i != 0 && v[i] == v[i - 1]) continue;
		res++;
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
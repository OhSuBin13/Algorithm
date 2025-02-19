#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> v;
int res = 0;

void Input() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int weight;
		cin >> weight;
		v.push_back(weight);
	}

	sort(v.begin(), v.end());
}

void Solution() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == C) {
			res = 1;
			break;
		}
	}

	if (res) return;

	int left = 0;
	int right = N - 1;
	while (left < right) {
		int sum = v[left] + v[right];
		if (sum < C) {
			left++;
		}
		else if (sum > C) {
			right--;
		}
		else {
			res = 1;
			break;
		}
	}

	if (res) return;

	for (int i = 0; i < N - 2; i++) {
		int target = C - v[i];
		int left = i + 1, right = N - 1;
		while (left < right) {
			int sum = v[left] + v[right];
			if (sum == target) {
				res = 1;
				break;
			}
			else if (sum < target) left++;
			else right--;
		}
	}
}

void Solve() {
	Input();
	Solution();
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Solve();

	return 0;
}
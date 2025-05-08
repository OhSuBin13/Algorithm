#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<int> hole;
vector<int> v;
vector<pair<int, int>> x;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		hole.push_back(num);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	x.push_back(make_pair(1, hole[0]));
	for (int i = 1; i < N; i++) {
		int index = i;
		int num = hole[i] + i;
		if (num <= x[x.size() - 1].second) continue;
		x.push_back(make_pair(index + 1, num));
	}
	//cout << x.size();
}

int binary_search(int num) {
	int start = 0, endNum = x.size()-1;
	int mid = 0;
	while (start < endNum) {
		mid = (start + endNum) / 2;
		if (x[mid].second == num) return x[mid].first;
		else if (x[mid].second > num) endNum = mid;
		else start = mid + 1;
		//cout << start << " " << endNum << "\n";
	}
	if (x[mid].second < num) return x[mid + 1].first;
	return x[mid].first;
}

void Solution() {
	for (int i = 0; i < v.size(); i++) {
		cout << binary_search(v[i]) << " ";
	}
}

void Solve() {
	Input();
	Solution();
}

int main() {
	Solve();
	return 0;
}
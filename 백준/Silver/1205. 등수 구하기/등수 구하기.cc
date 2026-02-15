#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, score, P;
	vector<int> v;
	cin >> N >> score >> P;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	if (N != 0 && v[N - 1] >= score && N == P) {
		cout << -1;
		return 0;
	}
	if (N == 0) {
		cout << 1;
		return 0;
	}
	int rank = 1;
	for (int i = 0; i < N; i++) {
		if (score == v[i] || score > v[i]) {
			cout << rank;
			return 0;
		}
		else if (score < v[i]) rank++;
	}
	cout << rank;
	return 0;
}
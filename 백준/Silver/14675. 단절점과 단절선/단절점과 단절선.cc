#include <iostream>
#include <vector>

using namespace std;

int N, q;
vector<vector<int>> v;

void Input() {
	cin >> N;

	v.resize(N+1);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	
}

void Solve() {
	cin >> q;
	while (q--) {
		int t, k;
		
		cin >> t >> k;
		if (t == 1) {
			if (v[k].size() == 1) {
				cout << "no" << "\n";
			}
			else cout << "yes" << "\n";

		}
		else if (t == 2) {
			cout << "yes" << "\n";
		}
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
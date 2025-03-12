#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N; cin >> N;
	stack<pair<int,int>> s;
	vector<int> v(N);
	
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		while (!s.empty() && s.top().second < num) {
			int index = s.top().first;
			v[index] = num;
			s.pop();
		}
		s.push({ i, num });
	}

	while (!s.empty()) {
		int index = s.top().first;
		v[index] = -1;
		s.pop();
	}
	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}

	return 0;
}
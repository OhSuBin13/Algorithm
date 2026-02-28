#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> a) {
	int maxNum = a[0];
	for (int i = 0; i < a.size(); i++) {

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<int> v;
	vector<int> answer(N, 0);
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		int j = 0;
		while (v[i] != 0) {
			if (answer[j] == 0) v[i]--;
			j++;
		}
		while (answer[j] != 0) j++;
		answer[j] = i + 1;
	}
	
	for (int i = 0; i < N; i++) {
		cout << answer[i] << ' ';
	}
	return 0;
}
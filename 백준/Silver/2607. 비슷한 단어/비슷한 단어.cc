#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
비슷한 단어
1. 단어가 같은 구성
2. 한 단어에서 문자 하나 빼거나 더하기
3. 한 문자 다른 문자 교체
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<string> v;
	map<char, int> m;
	int size, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		if (i == 0) {
			for (auto& i : word) {
				m[i]++;
			}
			size = word.size();
		}
		else if (size <= word.size()) {
			map<char, int> tmp = m;
			int diff = 0;
			for (auto& i : word) {
				if (tmp[i]) {
					tmp[i]--;
				}
				else {
					diff++;
				}
			}
			if (diff <= 1) {
				ans++;
			}
		}
		else {
			map<char, int> tmp = m;
			int diff = 0;
			for (auto& i : word) {
				if (tmp[i]) {
					tmp[i]--;
				}
				else {
					diff++;
				}
			}
			diff += size - word.size();
			if (diff <= 1) {
				ans++;
			}
		}

	}
	cout << ans;
	return 0;
}
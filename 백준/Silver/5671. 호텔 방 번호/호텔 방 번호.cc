#include <iostream>
#include <cstring>
using namespace std;

int counter[10];
int res = 0;

int main() {
	int N, M;

	while (cin >> N >> M) {
		res = 0;
		for (int i = N; i <= M; i++) {
			memset(counter, 0, sizeof(counter));
			int tmp = i;
			bool flag = true;
			while (tmp != 0) {
				counter[tmp % 10]++;
				if (counter[tmp % 10] > 1) {
					flag = false;
					break;
				}
				tmp /= 10;
			}
			if(flag) res++;
		}
		cout << res << "\n";
	}
}
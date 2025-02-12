#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
vector<long long int> sum;
long long int objectNum;
bool flag = true;
int res = 0;

void Input() {
	cin >> N;
	sum.resize(N);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);	
	}

	sum[0] = v[0];

	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + v[i];
	}

	if (sum[N - 1] % 4 == 0) objectNum = sum[N - 1] / 4;
	else flag = false;
}

void BackTracking(int start, int cnt) {
	if (cnt == 4) {
		res++;
		return;
	}

	if (start >= N) {
		return;
	}

	if (cnt == 3 && sum[N-1] - sum[start-1] == objectNum) {
		BackTracking(N, cnt + 1);
		return;
	}

	for (int i = start; i < N; i++) {
		if (sum[i] - sum[start - 1] == objectNum) {
			BackTracking(i + 1, cnt + 1);
		}
	}
}

void Solution() {
	if (!flag) {
		res = 0;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (sum[i] == objectNum) {
			BackTracking(i + 1, 1);
		}
	}
}

void Solve() {
	Input();
	Solution();
	cout << res;
}

int main() {
	Solve();
	return 0;
}
#include <iostream>
using namespace std;

int DP[1001];
int arr[1001];
int N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int minNum, maxNum;

	for (int i = 1; i <= N; i++) {
		minNum = arr[i], maxNum = arr[i];
		for (int j = i; j > 0; j--) {
			minNum = min(minNum, arr[j]);
			maxNum = max(maxNum, arr[j]);
			DP[i] = max(DP[i], DP[j - 1] + maxNum - minNum);
		}
	}


	cout << DP[N];
}
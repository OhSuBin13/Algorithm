#include <iostream>
using namespace std;


int main() {
	int P;
	cin >> P;
	for (int k = 1; k <= P; k++) {
		int arr[20];
		int ans = 0;
		int testNum; cin >> testNum;
		for (int i = 0; i < 20; i++) {
			int num; cin >> num;
			arr[i] = num;
			int maxNum = 0;
			int maxPos = 0;
			for (int j = 0; j < i; j++) {
				if (arr[i] < arr[j]) {
					maxNum = arr[j];
					maxPos = j;
					break;
				}
			}
			if (maxNum > arr[i]) {
				int tmp = arr[i];
				for (int j = i - 1; j >= maxPos; j--) {
					arr[j + 1] = arr[j];
					ans++;
				}
				arr[maxPos] = tmp;
			}
		}
		cout << testNum << " " << ans << "\n";
	}
	return 0;
}
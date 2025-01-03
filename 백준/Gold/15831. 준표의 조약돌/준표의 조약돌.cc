#include <iostream>
#include <string>
using namespace std;

int N, B, W;
int res = 0;
string road;

int main() {
	cin >> N >> B >> W;
	cin >> road;

	int bNum = 0, wNum = 0;
	int roadLength = 0;
	int start = 0;

	for (int i = 0; i < road.size(); i++) {
		(road[i] == 'W') ? wNum++ : bNum++;
		while (bNum > B) {
			(road[start] == 'W') ? wNum-- : bNum--;
			start++;
			roadLength--;
		}
		roadLength++;
		if (wNum >= W) res = max(res, roadLength);
	}
	cout << res;
}
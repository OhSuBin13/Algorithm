#include <iostream>
using namespace std;


int main() {
	int H, W, N, M;
	cin >> H >> W >> N >> M;
	int ans = 0;

	for (int i = 0; i < W; i += M + 1) {
		for (int j = 0; j < H; j += N + 1) ans++;
	}
	cout << ans;
	return 0;
}
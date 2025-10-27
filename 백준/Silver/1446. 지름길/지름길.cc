#include <iostream>
#include <cstring>
#include <vector>
#define INF 10001
using namespace std;

int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, D;
	cin >> N >> D;
	vector<pair<int, int>> highway[10001];
	for(int i = 0; i < N; i++) {
		int src, dist, dst;
		cin >> src >> dst >> dist;
		highway[dst].push_back({ dist, src });
		// Process each cost and distance as needed
	}

	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= D; i++) {
		dp[i] = dp[i - 1] + 1; // Normal road cost
		for(auto& hw : highway[i]) {
			int dist = hw.first;
			int src = hw.second;
			if(dp[src] + dist < dp[i]) {
				dp[i] = dp[src] + dist; // Update with highway cost if cheaper
			}
		}
	}
	cout << dp[D];

	return 0;
}
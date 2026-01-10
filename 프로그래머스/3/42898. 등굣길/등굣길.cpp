#include <vector>
#include <iostream>
using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    //dp[i][j] = dp[i][j-1] + dp[i-1][j]
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0], y = puddles[i][1];
        dp[y][x] = -1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == -1) continue;
            else if (dp[i][j - 1] == -1) dp[i][j] = dp[i - 1][j];
            else if (dp[i - 1][j] == -1) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}
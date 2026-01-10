#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<int> dp[9];
    dp[1].push_back(N);
    dp[2].push_back(N * 10 + N);
    dp[3].push_back(N * 100 + N * 10 + N);
    dp[4].push_back(N * 1000 + N * 100 + N * 10 + N);
    if (N < 3) dp[5].push_back(N * 10000 + N * 1000 + N * 100 + N * 10 + N);
    if (N == number) return 1;
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 0; k < dp[j].size(); k++) {
                int a = dp[j][k];
                for (int l = 0; l < dp[i - j].size(); l++) {
                    int b = dp[i - j][l];
                    if (b == 0) continue;
                    dp[i].push_back(a + b);
                    dp[i].push_back(a - b);
                    dp[i].push_back(a * b);
                    dp[i].push_back(a / b);
                }
            }
        }
        for (int j = 0; j < dp[i].size(); j++) {
            if (dp[i][j] == number) {
                return i;
            }
        }
    }
    return -1;
}

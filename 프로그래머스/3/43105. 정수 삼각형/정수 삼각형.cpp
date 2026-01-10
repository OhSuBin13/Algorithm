#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    //dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
    //dp[0][0] = triangle[0][0]
    //dp[1][0] = dp[0][0] + triangle[1][0], dp[1][1] = dp[0][0] + triangle[1][1]
    int answer = 0;
    int dp[500][500];
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) dp[i][0] = dp[i - 1][0] + triangle[i][0];
            else if (j == triangle[i].size() - 1) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }
    for (int i = 0; i < triangle.size(); i++) {
        answer = max(answer, dp[triangle.size() - 1][i]);
    }
    return answer;
}
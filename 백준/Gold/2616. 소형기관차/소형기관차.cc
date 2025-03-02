#include <iostream>

using namespace std;
int ps[50001] = { 0, };
int dp[4][50001] = { 0, };
int result = 0;

int main() {
    int n, k, tmp;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        //누적합
        ps[i] = ps[i - 1] + tmp;
    }

    cin >> k;

    //dp배열을 구하는 부분 - 객차는 1번부터 3번까지
    for (int i = 1; i <= 3; i++) {
        //j번째까지의 객차를 선택하기 때문에 i*k번째 객차부터 선택
        for (int j = i * k; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + ps[j] - ps[j - k]);
        }
    }

    cout << dp[3][n] << endl;
    return 0;
}
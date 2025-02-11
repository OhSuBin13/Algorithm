#include <iostream>
using namespace std;
int n, k;
int c[111], m[111];
int dp[11111];
int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> c[i] >> m[i];
    dp[0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = n; j >= 0; j--) {
            if (dp[j]) {
                for (int l = 1; l <= m[i] and j + c[i] * l <= n; l++) {
                    dp[j + c[i] * l] += dp[j];
                }
            }
        }
    }
    cout << dp[n];
    return 0;
}

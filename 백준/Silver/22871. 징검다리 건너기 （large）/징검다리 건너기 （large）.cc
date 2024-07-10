#include <bits/stdc++.h>
using namespace std;

using ld = long long;
int main() {
    int n;
    cin >> n;
    int a[n+1];
    ld dp[n+1];
    for (int i=1; i<=n; i++)
        cin >> a[i];
    dp[1] = 0;
    for (ld i=2; i<=n; i++) {
        dp[i] = 5e9;
        for (ld j=1; j<i; j++) {
            ld v = (i-j)*(1+abs(a[i]-a[j]));
            dp[i] = min(dp[i], max(dp[j],v));
        }
    }
    cout << dp[n];
}
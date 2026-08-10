class Solution {

    private static final long MOD = 1_000_000_007L;

    public int solution(int n) {
        long[] dp = new long[n + 1];
        long[] sum = new long[n + 1];

        dp[0] = 1;
        sum[0] = 1;

        for (int i = 1; i <= n; i++) {
            long value = 0;

            value += dp[i - 1];

            if (i >= 2) {
                value += 2 * dp[i - 2];
            }

            if (i >= 3) {
                value += 5 * dp[i - 3];
            }

            if (i >= 4) {
                value += 2 * sum[i - 4];
            }

            if (i >= 5) {
                value += 2 * sum[i - 5];
            }

            if (i >= 6) {
                value += 4 * sum[i - 6];
            }

            dp[i] = value % MOD;

            sum[i] = dp[i];

            if (i >= 3) {
                sum[i] = (sum[i] + sum[i - 3]) % MOD;
            }

        }
        return (int) dp[n];
    }
}
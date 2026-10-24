import java.util.function.Function;

class Solution {
    public int solution(int[] depth, int money, Function<Integer, Integer> excavate) {
        int w = depth.length;
        int[][] dp = new int[w + 2][w + 2];
        int[][] pick = new int[w + 2][w + 2];

        for (int len = 1; len <= w; len++) {
            for (int l = 1; l + len - 1 <= w; l++) {
                int r = l + len - 1;
                int best = Integer.MAX_VALUE, bestK = l;
                for (int k = l; k <= r; k++) {
                    int left = (k - 1 >= l) ? dp[l][k-1] : 0;
                    int right = (k + 1 <= r) ? dp[k+1][r] : 0;
                    int cost = depth[k - 1] + Math.max(left, right);
                    if (cost < best) {
                        best = cost;
                        bestK = k;
                    }
                }
                dp[l][r] = best;
                pick[l][r] = bestK;
            }
        }

        int l = 1, r = w;
        while (l <= r) {
            int k = pick[l][r];
            int res = excavate.apply(k);
            if (res == 0) return k;
            if (res < 0) r = k - 1;
            else l = k + 1;
        }
        return -1;
    }
}
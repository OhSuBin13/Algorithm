import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int target) {
        List<int[]> scores = new ArrayList<>();

        for (int i = 1; i <= 20; i++) {
            scores.add(new int[] { i, 1 });
            scores.add(new int[] { i * 2, 0 });
            scores.add(new int[] { i * 3, 0 });
        }
        scores.add(new int[] { 50, 1 });

        int[][] dp = new int[target + 1][2];

        for (int i = 1; i <= target; i++) {
            dp[i][0] = Integer.MAX_VALUE;
        }

        dp[0][0] = 0;
        dp[0][1] = 0;

        for (int score = 1; score <= target; score++) {
            for (int[] dart : scores) {
                int dartScore = dart[0];
                int singleOrBull = dart[1];

                if (score < dartScore) {
                    continue;
                }

                if (dp[score - dartScore][0] == Integer.MAX_VALUE) {
                    continue;
                }

                int dartCount = dp[score - dartScore][0] + 1;
                int singleOrBullCount = dp[score - dartScore][1] + singleOrBull;

                if (dartCount < dp[score][0]) {
                    dp[score][0] = dartCount;
                    dp[score][1] = singleOrBullCount;
                }
                else if (dartCount == dp[score][0] && singleOrBullCount > dp[score][1]) {
                    dp[score][1] = singleOrBullCount;
                }
            }
        }

        return dp[target];
    }
}
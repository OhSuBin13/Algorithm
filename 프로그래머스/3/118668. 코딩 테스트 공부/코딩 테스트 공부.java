import java.util.Arrays;

class Solution {
    public int solution(int alp, int cop, int[][] problems) {
        int targetAlp = 0;
        int targetCop = 0;

        for (int[] problem : problems) {
            targetAlp = Math.max(targetAlp, problem[0]);
            targetCop = Math.max(targetCop, problem[1]);
        }

        alp = Math.min(alp, targetAlp);
        cop = Math.min(cop, targetCop);

        int[][] dp = new int[targetAlp + 1][targetCop + 1];

        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        dp[alp][cop] = 0;

        for (int currentAlp = alp; currentAlp <= targetAlp; currentAlp++) {
            for (int currentCop = cop; currentCop <= targetCop; currentCop++) {

                if (dp[currentAlp][currentCop] == Integer.MAX_VALUE) {
                    continue;
                }

                if (currentAlp < targetAlp) {
                    dp[currentAlp + 1][currentCop] = Math.min(
                            dp[currentAlp + 1][currentCop],
                            dp[currentAlp][currentCop] + 1);
                }

                if (currentCop < targetCop) {
                    dp[currentAlp][currentCop + 1] = Math.min(
                            dp[currentAlp][currentCop + 1],
                            dp[currentAlp][currentCop] + 1);
                }

                for (int[] problem : problems) {
                    int alpReq = problem[0];
                    int copReq = problem[1];
                    int alpReward = problem[2];
                    int copReward = problem[3];
                    int cost = problem[4];

                    if (currentAlp < alpReq || currentCop < copReq)
                        continue;

                    int nextAlp = Math.min(targetAlp, currentAlp + alpReward);
                    int nextCop = Math.min(targetCop, currentCop + copReward);

                    dp[nextAlp][nextCop] = Math.min(
                            dp[nextAlp][nextCop],
                            dp[currentAlp][currentCop] + cost);
                }
            }
        }

        return dp[targetAlp][targetCop];
    }
}
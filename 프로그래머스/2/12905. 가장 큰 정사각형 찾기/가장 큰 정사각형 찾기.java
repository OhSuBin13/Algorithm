class Solution {
    public int solution(int[][] board) {
        int rows = board.length;
        int cols = board[0].length;

        int[][] dp = new int[rows + 1][cols + 1];
        int maxSide = 0;

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (board[i - 1][j - 1] == 1) {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    maxSide = Math.max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
}
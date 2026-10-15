class Solution {
    public int[] solution(int n) {
        int[][] tri = new int[n][n];
        int row = -1, col = 0, num = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i % 3 == 0) {
                    row++;
                } else if (i % 3 == 1) {
                    col++;
                } else {
                    row--;
                    col--;
                }
                tri[row][col] = num++;
            }
        }

        int[] answer = new int[n * (n + 1) / 2];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                answer[idx++] = tri[i][j];
            }
        }

        return answer;
    }
}
class Solution {
  public int solution(int m, int n, String[] board) {
    char[][] map = new char[m][n];

    for (int i = 0; i < m; i++) {
      map[i] = board[i].toCharArray();
    }

    int answer = 0;

    while (true) {
      boolean[][] removed = new boolean[m][n];

      for (int r = 0; r < m - 1; r++) {
        for (int c = 0; c < n - 1; c++) {
          char current = map[r][c];

          if (current == ' ') {
            continue;
          }

          if (map[r][c + 1] == current
              && map[r + 1][c] == current
              && map[r + 1][c + 1] == current) {
            removed[r][c] = true;
            removed[r + 1][c] = true;
            removed[r][c + 1] = true;
            removed[r + 1][c + 1] = true;
          }
        }
      }

      int count = 0;

      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (removed[r][c]) {
            map[r][c] = ' ';
            count++;
          }
        }
      }

      if (count == 0) {
        break;
      }

      answer += count;

      for (int c = 0; c < n; c++) {
        int bottom = m - 1;

        for (int r = m - 1; r >= 0; r--) {
          if (map[r][c] != ' ') {
            map[bottom][c] = map[r][c];

            if (bottom != r) {
              map[r][c] = ' ';
            }

            bottom--;
          }
        }
      }
    }

    return answer;
  }
}
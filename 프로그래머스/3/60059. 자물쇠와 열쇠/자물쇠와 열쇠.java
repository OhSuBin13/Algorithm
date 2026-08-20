class Solution {
  public boolean solution(int[][] key, int[][] lock) {
    int m = key.length;
    int n = lock.length;

    int size = n + 2 * (m - 1);
    int[][] board = new int[size][size];

    int offset = m - 1;

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        board[r + offset][c + offset] = lock[r][c];
      }
    }

    for (int rotation = 0; rotation < 4; rotation++) {
      for (int startRow = 0; startRow <= size - m; startRow++) {
        for (int startCol = 0; startCol <= size - m; startCol++) {
          addKey(board, key, startRow, startCol);

          if (isUnlocked(board, offset, n)) {
            return true;
          }

          removeKey(board, key, startRow, startCol);
        }
      }

      key = rotate(key);
    }

    return false;
  }

  private int[][] rotate(int[][] key) {
    int m = key.length;
    int[][] rotated = new int[m][m];

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < m; c++) {
        rotated[c][m - 1 - r] = key[r][c];
      }
    }

    return rotated;
  }

  private void removeKey(int[][] board, int[][] key, int startRow, int startCol) {
    int m = key.length;

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < m; c++) {
        board[startRow + r][startCol + c] -= key[r][c];
      }
    }
  }

  private boolean isUnlocked(int[][] board, int offset, int n) {
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (board[r + offset][c + offset] != 1) {
          return false;
        }
      }
    }

    return true;
  }

  private void addKey(int[][] board, int[][] key, int startRow, int startCol) {
    int m = key.length;

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < m; c++) {
        board[startRow + r][startCol + c] += key[r][c];
      }
    }
  }
}
class Solution {
  public long solution(int n, int m, int x, int y, int[][] queries) {
    long minRow = x;
    long maxRow = x;
    long minCol = y;
    long maxCol = y;

    for (int i = queries.length - 1; i >= 0; i--) {
      int command = queries[i][0];
      long dx = queries[i][1];

      switch (command) {
        case 0:
          if (minCol != 0) {
            minCol += dx;
          }

          maxCol = Math.min(m - 1L, maxCol + dx);
          break;

        case 1:
          minCol = Math.max(0L, minCol - dx);

          if (maxCol != m - 1L) {
            maxCol -= dx;
          }

          break;

        case 2:
          if (minRow != 0) {
            minRow += dx;
          }

          maxRow = Math.min(n - 1L, maxRow + dx);
          break;

        case 3:
          minRow = Math.max(0L, minRow - dx);

          if (maxRow != n - 1L) {
            maxRow -= dx;
          }
          break;
      }

      if (minRow > maxRow || minCol > maxCol) {
        return 0;
      }

      if (minRow < 0 || maxRow >= n || minCol < 0 || maxCol >= m) {
        return 0;
      }
    }

    return (maxRow - minRow + 1) * (maxCol - minCol + 1);
  }
}
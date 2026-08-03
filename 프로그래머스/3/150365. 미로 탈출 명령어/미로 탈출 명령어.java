class Solution {
  private static final char[] DIRECTIONS = { 'd', 'l', 'r', 'u' };

  private static final int[] DX = { 1, 0, 0, -1 };
  private static final int[] DY = { 0, -1, 1, 0 };

  public String solution(int n, int m, int x, int y, int r, int c, int k) {
    int minimumDistance = manhattanDistance(x, y, r, c);

    if (minimumDistance > k || (k - minimumDistance) % 2 != 0) {
      return "impossible";
    }

    StringBuilder path = new StringBuilder();

    int currentX = x;
    int currentY = y;

    for (int move = 0; move < k; move++) {
      int remainingMoves = k - move - 1;

      for (int direction = 0; direction < 4; direction++) {
        int nextX = currentX + DX[direction];
        int nextY = currentY + DY[direction];

        if (!isInside(nextX, nextY, n, m)) {
          continue;
        }

        int distance = manhattanDistance(nextX, nextY, r, c);

        if (canReach(distance, remainingMoves)) {
          path.append(DIRECTIONS[direction]);

          currentX = nextX;
          currentY = nextY;
          break;
        }
      }
    }
    return path.toString();
  }

  private boolean canReach(int distance, int remainingMoves) {
    return distance <= remainingMoves
        && (remainingMoves - distance) % 2 == 0;
  }

  private boolean isInside(int x, int y, int n, int m) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  }

  private int manhattanDistance(int x1, int y1, int x2, int y2) {
    return Math.abs(x1 - x2) + Math.abs(y1 - y2);
  }
}

import java.util.Arrays;
import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

class Solution {
  public String[] solution(int[][] line) {
    Set<Point> points = new HashSet<>();

    long minX = Long.MAX_VALUE;
    long maxX = Long.MIN_VALUE;
    long minY = Long.MAX_VALUE;
    long maxY = Long.MIN_VALUE;

    for (int i = 0; i < line.length; i++) {
      for (int j = i + 1; j < line.length; j++) {
        long A = line[i][0];
        long B = line[i][1];
        long E = line[i][2];

        long C = line[j][0];
        long D = line[j][1];
        long F = line[j][2];

        long denominator = A * D - B * C;

        if (denominator == 0) {
          continue;
        }

        long xNumerator = B * F - E * D;
        long yNumerator = E * C - A * F;

        if (xNumerator % denominator != 0
            || yNumerator % denominator != 0) {
          continue;
        }

        long x = xNumerator / denominator;
        long y = yNumerator / denominator;

        Point point = new Point(x, y);
        points.add(point);

        minX = Math.min(minX, x);
        maxX = Math.max(maxX, x);
        minY = Math.min(minY, y);
        maxY = Math.max(maxY, y);
      }
    }

    int width = (int) (maxX - minX + 1);
    int height = (int) (maxY - minY + 1);

    char[][] board = new char[height][width];

    for (char[] row : board) {
      Arrays.fill(row, '.');
    }

    for (Point point : points) {
      int row = (int) (maxY - point.y);
      int col = (int) (point.x - minX);

      board[row][col] = '*';
    }

    String[] answer = new String[height];

    for (int i = 0; i < height; i++) {
      answer[i] = new String(board[i]);
    }

    return answer;
  }

  private static class Point {
    long x;
    long y;

    public Point(long x, long y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o)
        return true;
      if (!(o instanceof Point))
        return false;

      Point point = (Point) o;
      return x == point.x && y == point.y;
    }

    @Override
    public int hashCode() {
      return Objects.hash(x, y);
    }

  }
}
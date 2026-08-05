class Solution {
  public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
    int[] answer = new int[balls.length];

    for (int i = 0; i < balls.length; i++) {
      int targetX = balls[i][0];
      int targetY = balls[i][1];

      int minDistance = Integer.MAX_VALUE;

      // 왼쪽 벽
      if (!(startY == targetY && targetX < startX)) {
        int reflectedX = -targetX;
        minDistance = Math.min(
            minDistance,
            distanceSquard(startX, startY, reflectedX, targetY));
      }

      // 오른쪽 벽
      if (!(startY == targetY && targetX > startX)) {
        int reflectedX = 2 * m - targetX;
        minDistance = Math.min(
            minDistance,
            distanceSquard(startX, startY, reflectedX, targetY));
      }

      // 아래쪽 벽
      if (!(startX == targetX && targetY < startY)) {
        int reflectedY = -targetY;
        minDistance = Math.min(
            minDistance,
            distanceSquard(startX, startY, targetX, reflectedY));
      }

      // 위쪽 벽
      if (!(startX == targetX && targetY > startY)) {
        int reflectedY = 2 * n - targetY;
        minDistance = Math.min(
            minDistance,
            distanceSquard(startX, startY, targetX, reflectedY));
      }
      answer[i] = minDistance;
    }
    return answer;
  }

  private int distanceSquard(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
  }
}

import java.util.ArrayDeque;
import java.util.Queue;

class Solution {

  private static final int SIZE = 5;

  private final int[] dr = { -1, 1, 0, 0 };
  private final int[] dc = { 0, 0, -1, 1 };

  public int[] solution(String[][] places) {
    int[] answer = new int[places.length];

    for (int i = 0; i < places.length; i++) {
      answer[i] = isValid(places[i]) ? 1 : 0;
    }

    return answer;
  }

  private boolean isValid(String[] place) {
    for (int r = 0; r < SIZE; r++) {
      for (int c = 0; c < SIZE; c++) {
        if (place[r].charAt(c) == 'P') {
          if (!bfs(place, r, c)) {
            return false;
          }
        }
      }
    }

    return true;
  }

  private boolean bfs(String[] place, int startR, int startC) {
    Queue<int[]> queue = new ArrayDeque<>();
    boolean[][] visited = new boolean[SIZE][SIZE];

    queue.offer(new int[] { startR, startC, 0 });
    visited[startR][startC] = true;

    while (!queue.isEmpty()) {
      int[] current = queue.poll();

      int r = current[0];
      int c = current[1];
      int distance = current[2];

      if (distance == 2) {
        continue;
      }

      for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE) {
          continue;
        }

        if (visited[nr][nc]) {
          continue;
        }

        if (place[nr].charAt(nc) == 'X') {
          continue;
        }

        if (place[nr].charAt(nc) == 'P') {
          return false;
        }

        visited[nr][nc] = true;
        queue.offer(new int[] { nr, nc, distance + 1 });
      }
    }

    return true;
  }
}
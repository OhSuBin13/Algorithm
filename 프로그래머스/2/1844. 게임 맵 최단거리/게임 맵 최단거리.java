
import java.util.LinkedList;
import java.util.Queue;

class Solution {
  public int solution(int[][] maps) {
    int answer = -1;
    int n = maps.length;
    int m = maps[0].length;
    int[][] visited = new int[n][m];
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    Queue<int[]> queue = new LinkedList<>();
    visited[0][0] = 1;
    queue.offer(new int[]{0, 0});
    while (!queue.isEmpty()) {
      int[] current = queue.poll();
      int x = current[0];
      int y = current[1];
      if (x == n - 1 && y == m - 1) {
        answer = visited[x][y];
        break;
      }
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && visited[nx][ny] == 0) {
          visited[nx][ny] = visited[x][y] + 1;
          queue.offer(new int[]{nx, ny});
        }
      }
    }
    return answer;
  }
}


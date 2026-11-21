import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {

  static int[] dr = { -1, 1, 0, 0 };
  static int[] dc = { 0, 0, -1, 1 };

  static final int INF = Integer.MAX_VALUE;

  static class State implements Comparable<State> {
    int x;
    int y;
    int direction;
    int cost;

    State(int x, int y, int direction, int cost) {
      this.x = x;
      this.y = y;
      this.direction = direction;
      this.cost = cost;
    }

    @Override
    public int compareTo(State other) {
      return Integer.compare(this.cost, other.cost);
    }
  }

  public int solution(int[][] board) {
    int n = board.length;

    // 0~3: 이동방향, 4: 출발 상태
    int[][][] dist = new int[n][n][5];

    for (int[][] row : dist) {
      for (int[] col : row) {
        Arrays.fill(col, INF);
      }
    }

    PriorityQueue<State> pq = new PriorityQueue<>();

    // 출발점: 아직 이동 방향이 없음
    dist[0][0][4] = 0;
    pq.offer(new State(0, 0, 4, 0));

    while (!pq.isEmpty()) {
      State cur = pq.poll();
      int x = cur.x;
      int y = cur.y;
      int direction = cur.direction;
      int cost = cur.cost;

      //이미 더 저렴한 경로로 갱신된 상태라면 무시
      if (cost > dist[x][y][direction]) {
        continue;
      }

      if (x == n - 1 && y == n - 1) {
        return cost;
      }

      for (int i = 0; i < 4; i++) {
        int nx = x + dr[i];
        int ny = y + dc[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1) {
          continue;
        }

        int newCost = cost + (direction == 4 || direction == i ? 100 : 600);

        if (newCost < dist[nx][ny][i]) {
          dist[nx][ny][i] = newCost;
          pq.offer(new State(nx, ny, i, newCost));
        }
      }
    }
    return -1;
  }

}
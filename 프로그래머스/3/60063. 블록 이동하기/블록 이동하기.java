import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

class Solution {

  static class State {
    int r1, c1;
    int r2, c2;
    int time;

    State(int r1, int c1, int r2, int c2, int time) {
      if (r1 > r2 || (r1 == r2 && c1 > c2)) {
        int tempR = r1;
        int tempC = c1;

        r1 = r2;
        c1 = c2;

        r2 = tempR;
        c2 = tempC;
      }

      this.r1 = r1;
      this.c1 = c1;
      this.r2 = r2;
      this.c2 = c2;
      this.time = time;
    }

    String key() {
      return r1 + "," + c1 + "," + r2 + "," + c2;
    }
  }

  public int solution(int[][] board) {
    int n = board.length;

    Queue<State> queue = new ArrayDeque<>();
    Set<String> visited = new HashSet<>();

    State start = new State(0, 0, 0, 1, 0);

    queue.offer(start);
    visited.add(start.key());

    int[] dr = { -1, 1, 0, 0 };
    int[] dc = { 0, 0, -1, 1 };

    while (!queue.isEmpty()) {
      State current = queue.poll();

      if ((current.r1 == n - 1 && current.c1 == n - 1)
          || (current.r2 == n - 1 && current.c2 == n - 1)) {
        return current.time;
      }

      for (int d = 0; d < 4; d++) {
        int nr1 = current.r1 + dr[d];
        int nc1 = current.c1 + dc[d];

        int nr2 = current.r2 + dr[d];
        int nc2 = current.c2 + dc[d];

        if (canMove(board, nr1, nc1, nr2, nc2)) {
          addState(
              queue,
              visited,
              new State(nr1, nc1, nr2, nc2, current.time + 1));
        }
      }

      if (current.r1 == current.r2) {
        rotateHorizontal(board, current, queue, visited);
      } else {
        rotateVertical(board, current, queue, visited);
      }
    }

    return -1;
  }

  private void rotateHorizontal(int[][] board, State current, Queue<State> queue,
      Set<String> visited) {
    int n = board.length;

    for (int d : new int[] { -1, 1 }) {
      int nr = current.r1 + d;

      if (nr < 0 || nr >= n) {
        continue;
      }

      if (board[nr][current.c1] == 0 && board[nr][current.c2] == 0) {
        addState(queue, visited, new State(current.r1, current.c1, nr, current.c1, current.time + 1));
        addState(queue, visited, new State(current.r2, current.c2, nr, current.c2, current.time + 1));
      }
    }
  }

  private void rotateVertical(int[][] board, State current, Queue<State> queue,
      Set<String> visited) {
    int n = board.length;

    for (int d : new int[] { -1, 1 }) {
      int nc = current.c1 + d;

      if (nc < 0 || nc >= n) {
        continue;
      }

      if (board[current.r1][nc] == 0 && board[current.r2][nc] == 0) {
        addState(queue, visited, new State(current.r1, current.c1, current.r1, nc, current.time + 1));
        addState(queue, visited, new State(current.r2, current.c2, current.r2, nc, current.time + 1));
      }
    }
  }

  private boolean canMove(int[][] board, int r1, int c1, int r2, int c2) {
    int n = board.length;

    if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= n) {
      return false;
    }

    if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n) {
      return false;
    }

    return board[r1][c1] == 0 && board[r2][c2] == 0;
  }

  private void addState(Queue<State> queue, Set<String> visited, State next) {
    String key = next.key();

    if (visited.add(key)) {
      queue.offer(next);
    }
  }
}
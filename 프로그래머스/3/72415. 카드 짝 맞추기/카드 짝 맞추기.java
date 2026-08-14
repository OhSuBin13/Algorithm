
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class Solution {

  private static final int SIZE = 4;

  private static final int[] DR = { -1, 1, 0, 0 };
  private static final int[] DC = { 0, 0, -1, 1 };

  private int answer = Integer.MAX_VALUE;

  public int solution(int[][] board, int r, int c) {
    dfs(board, r, c, 0);
    return answer;
  }

  private void dfs(int[][] board, int r, int c, int count) {
    boolean empty = true;

    for (int number = 1; number <= 6; number++) {
      List<int[]> cards = findCards(board, number);

      if (cards.isEmpty()) {
        continue;
      }

      empty = false;

      int[] first = cards.get(0);
      int[] second = cards.get(1);

      int move1 = bfs(board, r, c, first[0], first[1])
          + bfs(board, first[0], first[1], second[0], second[1])
          + 2;

      remove(board, first, second);

      dfs(board, second[0], second[1], count + move1);

      restore(board, first, second, number);

      int move2 = bfs(board, r, c, second[0], second[1])
          + bfs(board, second[0], second[1], first[0], first[1])
          + 2;

      remove(board, first, second);

      dfs(board, first[0], first[1], count + move2);

      restore(board, first, second, number);
    }

    if (empty) {
      answer = Math.min(answer, count);
    }
  }

  private int bfs(int[][] board, int startR, int startC, int targetR, int targetC) {
    if (startR == targetR && startC == targetC) {
      return 0;
    }

    boolean[][] visited = new boolean[SIZE][SIZE];
    Queue<int[]> queue = new ArrayDeque<>();

    queue.offer(new int[] { startR, startC, 0 });
    visited[startR][startC] = true;

    while (!queue.isEmpty()) {
      int[] current = queue.poll();

      int r = current[0];
      int c = current[1];
      int distance = current[2];

      for (int d = 0; d < 4; d++) {
        int nr = r + DR[d];
        int nc = c + DC[d];

        if (isInside(nr, nc) && !visited[nr][nc]) {
          if (nr == targetR && nc == targetC) {
            return distance + 1;
          }

          visited[nr][nc] = true;
          queue.offer(new int[] { nr, nc, distance + 1 });
        }

        int[] ctrl = ctrlMove(board, r, c, d);
        nr = ctrl[0];
        nc = ctrl[1];

        if (!visited[nr][nc]) {
          if (nr == targetR && nc == targetC) {
            return distance + 1;
          }

          visited[nr][nc] = true;
          queue.offer(new int[] { nr, nc, distance + 1 });
        }
      }
    }

    return -1;
  }

  private int[] ctrlMove(int[][] board, int r, int c, int direction) {
    int nr = r;
    int nc = c;

    while (true) {
      int nextR = nr + DR[direction];
      int nextC = nc + DC[direction];

      if (!isInside(nextR, nextC)) {
        return new int[] { nr, nc };
      }

      nr = nextR;
      nc = nextC;

      if (board[nr][nc] != 0) {
        return new int[] { nr, nc };
      }
    }
  }

  private List<int[]> findCards(int[][] board, int number) {
    List<int[]> cards = new ArrayList<>();

    for (int r = 0; r < SIZE; r++) {
      for (int c = 0; c < SIZE; c++) {
        if (board[r][c] == number) {
          cards.add(new int[] { r, c });
        }
      }
    }

    return cards;
  }

  private void remove(int[][] board, int[] first, int[] second) {
    board[first[0]][first[1]] = 0;
    board[second[0]][second[1]] = 0;
  }

  private void restore(int[][] board, int[] first, int[] second, int number) {
    board[first[0]][first[1]] = number;
    board[second[0]][second[1]] = number;
  }

  private boolean isInside(int r, int c) {
    return 0 <= r && r < SIZE && 0 <= c && c < SIZE;
  }

}
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private int rows;
    private int cols;
    private String[] board;

    private final int[] dr = {-1, 1, 0, 0};
    private final int[] dc = {0, 0, -1, 1};

    public int solution(String[] board) {
      this.board = board;
      this.rows = board.length;
      this.cols = board[0].length();

      int startRow = 0;
      int startCol = 0;

      for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
          if (board[row].charAt(col) == 'R') {
            startRow = row;
            startCol = col;
          }
        }
      }

      boolean[][] visited = new boolean[rows][cols];
      Queue<int[]> queue = new ArrayDeque<>();

      queue.offer(new int[]{startRow, startCol, 0});
      visited[startRow][startCol] = true;

      while(!queue.isEmpty()) {
        int[] current = queue.poll();

        int row = current[0];
        int col = current[1];
        int moveCount = current[2];

        if (board[row].charAt(col) == 'G') {
          return moveCount;
        }

        for (int direction = 0; direction < 4; direction++) {
          int nextRow = row;
          int nextCol = col;

          while (canMove(
            nextRow + dr[direction],
            nextCol + dc[direction]
          )) {
            nextRow += dr[direction];
            nextCol += dc[direction];
          }

          if ((nextRow != row || nextCol != col)
            && !visited[nextRow][nextCol]) {
              visited[nextRow][nextCol] = true;
              queue.offer(new int[]{
                nextRow,
                nextCol,
                moveCount + 1
              });
            }
        }
      }
      return -1;
    }

    private boolean canMove(int row, int col) {
      return row >= 0 && row < rows
        && col >= 0 && col < cols
        && board[row].charAt(col) != 'D';
    }
}
import java.util.*;

class Solution {
    public int[] solution(String[] maps) {
        int rows = maps.length;
        int cols = maps[0].length();

        boolean[][] visited = new boolean[rows][cols];
        List<Integer> islands = new ArrayList<>();

        int[] dr = {-1, 1, 0, 0}; // row direction
        int[] dc = {0, 0, -1, 1}; // column

        for (int row = 0; row < rows; row++) {
          for (int col = 0; col < cols; col++) {
            if (maps[row].charAt(col) == 'X' || visited[row][col]) continue;

            int food = 0;
            Queue<int[]> queue = new ArrayDeque<>();

            queue.offer(new int[]{row, col});
            visited[row][col] = true;

            while (!queue.isEmpty()) {
              int[] current = queue.poll();
              int currentRow = current[0];
              int currentCol = current[1];

              food += maps[currentRow].charAt(currentCol) - '0';

              for (int direction = 0; direction < 4; direction++) {
                int nextRow = currentRow + dr[direction];
                int nextCol = currentCol + dc[direction];

                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) continue;

                if (maps[nextRow].charAt(nextCol) == 'X' || visited[nextRow][nextCol]) continue;

                visited[nextRow][nextCol] = true;
                queue.offer(new int[]{nextRow, nextCol});
              }
            }
            islands.add(food);
          }
        }

        if (islands.isEmpty()) {
          return new int[]{-1};
        }

        Collections.sort(islands);

        return islands.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}
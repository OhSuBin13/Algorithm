class Solution {
  public int solution(String dirs) {
    int answer = 0;
    boolean[][][] visited = new boolean[11][11][4]; // 0: up, 2: down, 1: left, 3: right
    int x = 5, y = 5; // Starting point

    for (char dir : dirs.toCharArray()) {
      int nx = x, ny = y;
      int direction = -1;

      switch (dir) {
        case 'U':
          ny++;
          direction = 0;
          break;
        case 'D':
          ny--;
          direction = 2;
          break;
        case 'L':
          nx--;
          direction = 1;
          break;
        case 'R':
          nx++;
          direction = 3;
          break;
      }

      if (nx < 0 || nx > 10 || ny < 0 || ny > 10) {
        continue; // Out of bounds
      }

      if (!visited[x][y][direction]) {
        visited[x][y][direction] = true;
        visited[nx][ny][(direction + 2) % 4] = true; // Mark the reverse direction as visited
        answer++;
      }

      x = nx;
      y = ny;
    }

    return answer;
  }
}
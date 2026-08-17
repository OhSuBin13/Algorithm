import java.util.ArrayList;
import java.util.List;

class Solution {

  private boolean[][] pillar;
  private boolean[][] beam;
  private int n;

  public int[][] solution(int n, int[][] build_frame) {
    this.n = n;

    pillar = new boolean[n + 1][n + 1];
    beam = new boolean[n + 1][n + 1];

    for (int[] command : build_frame) {
      int x = command[0];
      int y = command[1];
      int type = command[2];
      int action = command[3];

      if (action == 1) {
        if (type == 0) {
          pillar[x][y] = true;
        } else {
          beam[x][y] = true;
        }

        if (!isValidStructure()) {
          if (type == 0) {
            pillar[x][y] = false;
          } else {
            beam[x][y] = false;
          }
        }
      } else {
        if (type == 0) {
          pillar[x][y] = false;
        } else {
          beam[x][y] = false;
        }

        if (!isValidStructure()) {
          if (type == 0) {
            pillar[x][y] = true;
          } else {
            beam[x][y] = true;
          }
        }
      }
    }

    List<int[]> result = new ArrayList<>();

    for (int x = 0; x <= n; x++) {
      for (int y = 0; y <= n; y++) {
        if (pillar[x][y]) {
          result.add(new int[] { x, y, 0 });
        }

        if (beam[x][y]) {
          result.add(new int[] { x, y, 1 });
        }
      }
    }

    return result.toArray(new int[result.size()][]);
  }

  private boolean isValidStructure() {
    for (int x = 0; x <= n; x++) {
      for (int y = 0; y <= n; y++) {
        if (pillar[x][y] && !canBuildPillar(x, y)) {
          return false;
        }

        if (beam[x][y] && !canBuildBean(x, y)) {
          return false;
        }
      }
    }

    return true;
  }

  private boolean canBuildPillar(int x, int y) {
    if (y == 0) {
      return true;
    }

    if (x > 0 && beam[x - 1][y]) {
      return true;
    }

    if (beam[x][y]) {
      return true;
    }

    if (y > 0 && pillar[x][y - 1]) {
      return true;
    }

    return false;
  }

  private boolean canBuildBean(int x, int y) {
    if (y > 0 && pillar[x][y - 1]) {
      return true;
    }

    if (x < n && y > 0 && pillar[x + 1][y - 1]) {
      return true;
    }

    if (x > 0 && x < n && beam[x - 1][y] && beam[x + 1][y]) {
      return true;
    }

    return false;
  }
}
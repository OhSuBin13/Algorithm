
import java.util.Arrays;

class Solution {

  private static final int KEY_COUNT = 10;
  private static final int INF = 1_000_000_000;

  public int solution(String numbers) {
    int[][] moveCost = createMoveCost();

    int[][] dp = new int[KEY_COUNT][KEY_COUNT];

    for (int[] row : dp) {
      Arrays.fill(row, INF);
    }

    dp[4][6] = 0;

    for (int index = 0; index < numbers.length(); index++) {
      int target = numbers.charAt(index) - '0';

      int[][] next = new int[KEY_COUNT][KEY_COUNT];

      for (int[] row : next) {
        Arrays.fill(row, INF);
      }

      for (int left = 0; left < KEY_COUNT; left++) {
        for (int right = 0; right < KEY_COUNT; right++) {
          if (dp[left][right] == INF) {
            continue;
          }

          int currentCost = dp[left][right];

          if (left == target) {
            next[left][right] = Math.min(
                next[left][right],
                currentCost + 1);
            continue;
          }

          if (right == target) {
            next[left][right] = Math.min(
                next[left][right],
                currentCost + 1);
            continue;
          }

          next[target][right] = Math.min(
              next[target][right],
              currentCost + moveCost[left][target]);

          next[left][target] = Math.min(
              next[left][target],
              currentCost + moveCost[right][target]);
        }
      }

      dp = next;
    }

    int answer = INF;

    for (int left = 0; left < KEY_COUNT; left++) {
      for (int right = 0; right < KEY_COUNT; right++) {
        answer = Math.min(answer, dp[left][right]);
      }
    }
    return answer;
  }

  private int[][] createMoveCost() {
    int[][] positions = {
        { 3, 1 },
        { 0, 0 },
        { 0, 1 },
        { 0, 2 },
        { 1, 0 },
        { 1, 1 },
        { 1, 2 },
        { 2, 0 },
        { 2, 1 },
        { 2, 2 }
    };

    int[][] cost = new int[KEY_COUNT][KEY_COUNT];

    for (int i = 0; i < KEY_COUNT; i++) {
      Arrays.fill(cost[i], INF);
      cost[i][i] = 0;
    }

    for (int from = 0; from < KEY_COUNT; from++) {
      for (int to = 0; to < KEY_COUNT; to++) {
        if (from == to) {
          continue;
        }

        int rowDifference = Math.abs(positions[from][0] - positions[to][0]);
        int columnDifference = Math.abs(positions[from][1] - positions[to][1]);

        if (rowDifference > 1 || columnDifference > 1) {
          continue;
        }

        if (rowDifference + columnDifference == 1) {
          cost[from][to] = 2;
        } else if (rowDifference == 1 && columnDifference == 1) {
          cost[from][to] = 3;
        }
      }
    }

    for (int middle = 0; middle < KEY_COUNT; middle++) {
      for (int from = 0; from < KEY_COUNT; from++) {
        for (int to = 0; to < KEY_COUNT; to++) {
          cost[from][to] = Math.min(
              cost[from][to],
              cost[from][middle] + cost[middle][to]);
        }
      }
    }

    for (int digit = 0; digit < KEY_COUNT; digit++) {
      cost[digit][digit] = 1;
    }

    return cost;
  }
}
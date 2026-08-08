
import java.util.Arrays;

class Solution {

  private static final int MIN_TEMP = -10;
  private static final int MAX_TEMP = 40;
  private static final int OFFSET = 10;
  private static final int INF = 1_000_000_000;

  public int solution(int temperature, int t1, int t2, int a, int b, int[] onboard) {
    int n = onboard.length;

    int[] dp = new int[51];
    Arrays.fill(dp, INF);

    dp[temperature + OFFSET] = 0;

    for (int time = 0; time < n - 1; time++) {
      int[] next = new int[51];
      Arrays.fill(next, INF);

      for (int cur = MIN_TEMP; cur <= MAX_TEMP; cur++) {
        int curCost = dp[cur + OFFSET];

        if (curCost == INF) {
          continue;
        }

        int offNext;

        if (cur < temperature) {
          offNext = cur + 1;
        } else if (cur > temperature) {
          offNext = cur - 1;
        } else {
          offNext = cur;
        }

        update(next, offNext, curCost, onboard[time + 1], t1, t2);

        update(next, cur, curCost + b, onboard[time + 1], t1, t2);

        if (cur > MIN_TEMP) {
          update(next, cur - 1, curCost + a, onboard[time + 1], t1, t2);
        }

        if (cur < MAX_TEMP) {
          update(next, cur + 1, curCost + a, onboard[time + 1], t1, t2);
        }
      }
      dp = next;
    }
    int answer = INF;

    for (int temp = MIN_TEMP; temp <= MAX_TEMP; temp++) {
      if (isValidTemperature(temp, onboard[n - 1], t1, t2)) {
        answer = Math.min(answer, dp[temp + OFFSET]);
      }
    }

    return answer;
  }

  private void update(int[] next, int temp, int cost, int onboard, int t1, int t2) {
    if (!isValidTemperature(temp, onboard, t1, t2)) {
      return;
    }

    int index = temp + OFFSET;
    next[index] = Math.min(next[index], cost);
  }

  private boolean isValidTemperature(int temp, int onboard, int t1, int t2) {
    if (onboard == 0) {
      return true;
    }

    return t1 <= temp && temp <= t2;
  }
}
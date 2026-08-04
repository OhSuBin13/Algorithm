
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
  public int solution(int k, int n, int[][] reqs) {
    // 유형별 상담 요청 분리
    List<int[]>[] requestsByType = new ArrayList[k + 1];

    for (int type = 1; type <= k; type++) {
      requestsByType[type] = new ArrayList<>();
    }

    for (int[] req : reqs) {
      int startTime = req[0];
      int endTime = req[1];
      int type = req[2];

      requestsByType[type].add(new int[] { startTime, endTime });
    }

    /*
     * waiting[type][mentorCount]
     *
     * type번 상담 유형에 mentorCount명의 멘토를 배정했을 때
     * 발생하는 총 대기 시간
     */
    int[][] waiting = new int[k + 1][n + 1];

    for (int type = 1; type <= k; type++) {
      for (int mentorCount = 1; mentorCount <= n; mentorCount++) {
        waiting[type][mentorCount] = calculateWaitingTime(
            requestsByType[type],
            mentorCount);
      }
    }

    /*
     * dp[typeCount][usedMentors]
     *
     * 1번부터 typeCount번 유형까지 멘토를 배정하고,
     * 총 usedMentors명을 사용했을 때의 최소 대기 시간
     */
    int INF = Integer.MAX_VALUE / 2;
    int[][] dp = new int[k + 1][n + 1];

    for (int[] row : dp) {
      Arrays.fill(row, INF);
    }

    dp[0][0] = 0;

    for (int type = 1; type <= k; type++) {
      for (int usedMentors = 0; usedMentors <= n; usedMentors++) {
        if (dp[type - 1][usedMentors] == INF) {
          continue;
        }

        /*
         * 현재 type에 mentorCount명을 배정한다.
         * 각 유형에는 최소 1명이 필요하다.
         */
        for (int mentorCount = 1; usedMentors + mentorCount <= n; mentorCount++) {
          int nextMentorCount = usedMentors + mentorCount;

          dp[type][nextMentorCount] = Math.min(
              dp[type][nextMentorCount],
              dp[type - 1][usedMentors] + waiting[type][mentorCount]);
        }
      }
    }

    return dp[k][n];
  }

  private int calculateWaitingTime(List<int[]> requests, int mentorCount) {
    /*
     * 각 멘토가 상담을 마치는 시간을 저장한다.
     *
     * 가장 빨리 상담이 끝나는 멘토를 찾아야 하므로
     * 최소 힙을 사용
     */
    PriorityQueue<Integer> finishTimes = new PriorityQueue<>();

    for (int i = 0; i < mentorCount; i++) {
      finishTimes.offer(0);
    }

    int totalWaitingTime = 0;

    for (int[] request : requests) {
      int requestTime = request[0];
      int duration = request[1];

      int availableTime = finishTimes.poll();
      int consultationStart = Math.max(requestTime, availableTime);

      totalWaitingTime += consultationStart - requestTime;
      finishTimes.offer(consultationStart + duration);
    }

    return totalWaitingTime;
  }
}
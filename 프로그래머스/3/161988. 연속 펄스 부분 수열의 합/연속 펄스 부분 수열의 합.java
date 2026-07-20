class Solution {
    public long solution(int[] sequence) {
        long currentFirstPositive = 0;
        long currentFirstNegative = 0;
        long answer = Long.MIN_VALUE;

        for (int i = 0; i < sequence.length; i++) {
          int pulse = (i % 2 == 0) ? 1 : -1;

          long firstPositive = (long) sequence[i] * pulse;

          long firstNegative = -firstPositive;

          if (i == 0) {
            currentFirstPositive = firstPositive;
            currentFirstNegative = firstNegative;
          } else {
            currentFirstPositive = Math.max(
              firstPositive,
              currentFirstPositive + firstPositive
            );

            currentFirstNegative = Math.max(
              firstNegative,
              currentFirstNegative + firstNegative
            );
          }

          answer = Math.max(answer, currentFirstPositive);
          answer = Math.max(answer, currentFirstNegative);
        }
        return answer;
    }
}
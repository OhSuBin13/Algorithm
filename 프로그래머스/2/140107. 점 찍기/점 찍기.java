class Solution {
    public long solution(int k, int d) {
        long answer = 0;
        long dSquard = (long) d * d;

        for (long x = 0; x <= d; x+= k) {
          long yMax = (long) Math.sqrt(dSquard - x * x);

          answer += yMax / k + 1;
        }

        return answer;
    }
}
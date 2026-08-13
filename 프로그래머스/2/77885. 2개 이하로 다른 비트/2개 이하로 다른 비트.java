class Solution {
  public long[] solution(long[] numbers) {
    long[] answer = new long[numbers.length];

    for (int i = 0; i < numbers.length; i++) {
      long x = numbers[i];

      if ((x & 1L) == 0) {
        answer[i] = x + 1;
      } else {
        answer[i] = x + 1 + ((x ^ (x + 1)) >> 2);
      }
    }

    return answer;
  }
}
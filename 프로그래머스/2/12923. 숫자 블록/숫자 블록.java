class Solution {

  private static final int MAX_BLOCK = 10_000_000;

  public int[] solution(long begin, long end) {
    int length = (int) (end - begin + 1);
    int[] answer = new int[length];

    for (int i = 0; i < length; i++) {
      long position = begin + i;
      answer[i] = getBlock(position);
    }

    return answer;
  }

  private int getBlock(long position) {
    if (position == 1) {
      return 0;
    }

    int candidate = 1;

    for (long divisor = 2; divisor * divisor <= position; divisor++) {
      if (position % divisor != 0) {
        continue;
      }

      long quotient = position / divisor;

      if (quotient <= MAX_BLOCK) {
        return (int) quotient;
      }

      candidate = (int) divisor;
    }

    return candidate;
  }
}
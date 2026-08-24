class Solution {

  private final long[] pow5 = new long[21];
  private final long[] pow4 = new long[21];

  public int solution(int n, long l, long r) {
    pow5[0] = 1;
    pow4[0] = 1;

    for (int i = 1; i <= n; i++) {
      pow5[i] = pow5[i - 1] * 5;
      pow4[i] = pow4[i - 1] * 4;
    }

    long answer = count(n, r) - count(n, l - 1);
    return (int) answer;
  }

  private long count(int n, long x) {
    if (x <= 0) {
      return 0;
    }

    if (n == 0) {
      return 1;
    }

    long blockLength = pow5[n - 1];
    long onesPerBlcok = pow4[n - 1];

    long block = x / blockLength;
    long remainder = x % blockLength;

    long result;

    if (block == 0) {
      result = 0;
    } else if (block == 1) {
      result = onesPerBlcok;
    } else if (block == 2) {
      result = 2 * onesPerBlcok;
    } else if (block == 3) {
      result = 2 * onesPerBlcok;
    } else if (block == 4) {
      result = 3 * onesPerBlcok;
    } else {
      return 4 * onesPerBlcok;
    }

    if (block == 2) {
      return result;
    }

    return result + count(n - 1, remainder);
  }
}
class Solution {
  public int solution(int[] arrayA, int[] arrayB) {
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];

    for (int i = 1; i < arrayA.length; i++) {
      gcdA = gcd(gcdA, arrayA[i]);
      gcdB = gcd(gcdB, arrayB[i]);
    }

    int answer = 0;

    if (cannotDivideAny(gcdA, arrayB)) {
      answer = Math.max(answer, gcdA);
    }

    if (cannotDivideAny(gcdB, arrayA)) {
      answer = Math.max(answer, gcdB);
    }

    return answer;
  }

    private int gcd(int a, int b) {
      while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
      }
      return a;
    }

    private boolean cannotDivideAny(int divisor, int[] array) {
      for (int value : array) {
        if (value % divisor == 0) {
          return false;
        }
      }

      return true;
    }
}
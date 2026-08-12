
import java.util.Arrays;

class Solution {
  public int solution(int[] A, int[] B) {
    Arrays.sort(A);
    Arrays.sort(B);

    int score = 0;
    int aPoint = 0;
    int bPoint = 0;

    while (aPoint != A.length && bPoint != B.length) {
      if (B[bPoint] > A[aPoint]) {
        score++;
        bPoint++;
        aPoint++;
      } else {
        bPoint++;
      }
    }

    return score;
  }
}
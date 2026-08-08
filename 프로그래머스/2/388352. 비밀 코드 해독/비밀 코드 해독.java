class Solution {
  public int solution(int n, int[][] q, int[] ans) {
    int count = 0;

    for (int a = 1; a <= n - 4; a++) {
      for (int b = a + 1; b <= n - 3; b++) {
        for (int c = b + 1; c <= n - 2; c++) {
          for (int d = c + 1; d <= n - 1; d++) {
            for (int e = d + 1; e <= n; e++) {
              int[] candidate = { a, b, c, d, e };

              if (isValid(candidate, q, ans)) {
                count++;
              }
            }
          }
        }
      }
    }

    return count;
  }

  private boolean isValid(int[] candidate, int[][] q, int[] ans) {
    for (int i = 0; i < q.length; i++) {
      int matchCount = 0;

      for (int num : q[i]) {
        for (int candidateNum : candidate) {
          if (num == candidateNum) {
            matchCount++;
            break;
          }
        }
      }

      if (matchCount != ans[i]) {
        return false;
      }
    }

    return true;
  }
}

import java.util.Arrays;

class Solution {
  public int solution(int[][] data, int col, int row_begin, int row_end) {
    int colIndex = col - 1;

    Arrays.sort(data, (a, b) -> {
      if (a[colIndex] != b[colIndex]) {
        return Integer.compare(a[colIndex], b[colIndex]);
      }

      return Integer.compare(b[0], a[0]);
    });

    int answer = 0;
    for (int i = row_begin; i <= row_end; i++) {
      int sum = 0;

      for (int value : data[i - 1]) {
        sum += value % i;
      }

      answer ^= sum;
    }

    return answer;
  }
}
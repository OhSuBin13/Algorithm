
import java.util.ArrayList;
import java.util.List;

class Solution {
  public int[] solution(int n, long k) {
    int[] answer = new int[n];

    long[] factorial = new long[n + 1];
    factorial[0] = 1;

    for (int i = 1; i <= n; i++) {
      factorial[i] = factorial[i - 1] * i;
    }

    List<Integer> numbers = new ArrayList<>();

    for (int i = 1; i <= n; i++) {
      numbers.add(i);
    }

    k--;

    for (int i = 0; i < n; i++) {
      long groupSize = factorial[n - 1 - i];

      int index = (int) (k / groupSize);

      answer[i] = numbers.remove(index);

      k %= groupSize;
    }

    return answer;
  }
}
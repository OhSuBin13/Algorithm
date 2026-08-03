import java.util.ArrayList;
import java.util.List;

class Solution {
  public double[] solution(int k, int[][] ranges) {
    List<Long> sequence = createCollatzSequence(k);

    int n = sequence.size() - 1;

    double[] prefixArea = new double[n + 1];

    for (int i = 0; i < n; i++) {
      long leftHeight = sequence.get(i);
      long rightHeight = sequence.get(i + 1);

      double trapezoidArea = (leftHeight + rightHeight) / 2.0;
      prefixArea[i + 1] = prefixArea[i] + trapezoidArea;
    }

    double[] answer = new double[ranges.length];

    for (int i = 0; i < ranges.length; i++) {
      int start = ranges[i][0];
      int end = n + ranges[i][1];

      if (start > end) {
        answer[i] = -1.0;
      } else {
        answer[i] = prefixArea[end] - prefixArea[start];
      }
    }

    return answer;
  }

  private List<Long> createCollatzSequence(int k) {
    List<Long> sequence = new ArrayList<>();

    long current = k;
    sequence.add(current);

    while (current != 1) {
      if (current % 2 == 0) {
        current /= 2;
      } else {
        current = current * 3 + 1;
      }

      sequence.add(current);
    }

    return sequence;
  }
}
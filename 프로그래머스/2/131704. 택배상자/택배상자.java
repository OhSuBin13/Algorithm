
import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
  public int solution(int[] order) {
    Deque<Integer> sub = new ArrayDeque<>();

    int nextBox = 1;
    int loaded = 0;

    for (int target : order) {
      while (nextBox < target) {
        sub.push(nextBox);
        nextBox++;
      }

      if (nextBox == target) {
        loaded++;
        nextBox++;
        continue;
      }

      if (!sub.isEmpty() && sub.peek() == target) {
        sub.pop();
        loaded++;
        continue;
      }

      break;
    }
    return loaded;

  }

}
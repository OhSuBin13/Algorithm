import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int solution(int k, int[] tangerine) {
      Map<Integer, Integer> frequencyMap = new HashMap<>();

      for (int size : tangerine) {
        frequencyMap.put(
          size,
          frequencyMap.getOrDefault(size, 0) + 1
        );
      }

      List<Integer> frequencies = new ArrayList<>(frequencyMap.values());

      frequencies.sort(Collections.reverseOrder());

      int selectedCount = 0;
      int typeCount = 0;

      for (int frequency : frequencies) {
        selectedCount += frequency;
        typeCount++;

        if (selectedCount >= k) {
          break;
        }
      }

      return typeCount;
    }
}
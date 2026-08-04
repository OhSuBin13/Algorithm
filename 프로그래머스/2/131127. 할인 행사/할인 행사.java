
import java.util.HashMap;
import java.util.Map;

class Solution {
  public int solution(String[] want, int[] number, String[] discount) {
    Map<String, Integer> required = new HashMap<>();

    for (int i = 0; i < want.length; i++) {
      required.put(want[i], number[i]);
    }

    Map<String, Integer> window = new HashMap<>();

    for (int i = 0; i < 10; i++) {
      window.merge(discount[i], 1, Integer::sum);
    }

    int answer = 0;

    if (isValid(required, window)) {
      answer++;
    }

    for (int right = 10; right < discount.length; right++) {
      int left = right - 10;

      String removedProduct = discount[left];
      window.put(removedProduct, window.get(removedProduct) - 1);

      if (window.get(removedProduct) == 0) {
        window.remove(removedProduct);
      }

      String addedProduct = discount[right];
      window.merge(addedProduct, 1, Integer::sum);

      if (isValid(required, window)) {
        answer++;
      }
    }

    return answer;
  }

  private boolean isValid(Map<String, Integer> required, Map<String, Integer> window) {
    for (Map.Entry<String, Integer> entry : required.entrySet()) {
      String product = entry.getKey();
      int requiredCount = entry.getValue();

      if (window.getOrDefault(product, 0) != requiredCount) {
        return false;
      }
    }

    return true;
  }
}
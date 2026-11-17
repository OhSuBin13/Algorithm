import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
  static Map<String, Integer> map = new HashMap<>();
  static List<String> result = new ArrayList<>();

  public String[] solution(String[] orders, int[] course) {

    for (int i = 0; i < orders.length; i++) {
      char[] orderChars = orders[i].toCharArray();
      Arrays.sort(orderChars);
      orders[i] = String.valueOf(orderChars);
    }

    for (int courseLen : course) {
      for (String order : orders) {
        comb(order, courseLen, "");
      }

      if (!map.isEmpty()) {
        List<Integer> cntList = new ArrayList<>(map.values());
        int max = Collections.max(cntList);

        if (max > 1) {
          for (String key : map.keySet()) {
            if (map.get(key) == max) {
              result.add(key);
            }
          }
        }

        map.clear();
      }
    }

    Collections.sort(result);

    return result.toArray(new String[0]);
  }

  private void comb(String order, int cnt, String tmp) {
    if (cnt == 0) {
      map.put(tmp, map.getOrDefault(tmp, 0) + 1);
    }

    for (int i = 0; i < order.length(); i++) {
      comb(order.substring(i + 1), cnt - 1, tmp + order.charAt(i));
    }
  }
}
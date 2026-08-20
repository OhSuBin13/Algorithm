
import java.util.HashMap;
import java.util.Map;

class Solution {
  public int solution(String str1, String str2) {
    str1 = str1.toLowerCase();
    str2 = str2.toLowerCase();

    Map<String, Integer> str1Map = new HashMap<>();
    Map<String, Integer> str2Map = new HashMap<>();

    int str1Size = 0;
    int str2Size = 0;

    for (int i = 0; i < str1.length() - 1; i++) {
      String key = str1.substring(i, i + 2);
      if (key.matches("[a-z]+")) {
        str1Map.put(key, str1Map.getOrDefault(key, 0) + 1);
        str1Size++;
      }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
      String key = str2.substring(i, i + 2);
      if (key.matches("[a-z]+")) {
        str2Map.put(key, str2Map.getOrDefault(key, 0) + 1);
        str2Size++;
      }
    }

    int intersection = 0;
    int union = 0;

    for (String key : str1Map.keySet()) {
      if (str2Map.containsKey(key)) {
        intersection += Math.min(str1Map.get(key), str2Map.get(key));
      }
    }

    union = str1Size + str2Size - intersection;

    if (union == 0) {
      return 65536;
    }
    double jakard = (double) intersection / union;
    int answer = (int) (jakard * 65536);
    return answer;
  }
}
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(String[][] clothes) {
        Map<String, Integer> map = new HashMap<>();

        for (String[] cloth : clothes) {
            String clothName = cloth[0];
            String clothType = cloth[1];

            map.put(clothType, map.getOrDefault(clothType, 0) + 1);
        }
        int answer = 1;
        for (String s : map.keySet()) {
            answer *= (map.get(s) + 1);
        }
        return answer - 1;
    }
}
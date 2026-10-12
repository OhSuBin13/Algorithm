import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int[] solution(String msg) {
        Map<String, Integer> dict = new HashMap<>();
        for (int i = 0; i < 26; i++) {
            dict.put(String.valueOf((char) ('A' + i)), i + 1);
        }
        int nextIndex = 27;

        List<Integer> answer = new ArrayList<>();
        int i = 0;
        int n = msg.length();

        while (i < n) {
            int j = i + 1;
            while (j <= n && dict.containsKey(msg.substring(i, j))) {
                j++;
            }
            String w = msg.substring(i, j - 1);
            answer.add(dict.get(w));

            if (j - 1 < n) {
                dict.put(msg.substring(i, j), nextIndex++);
            }
            i += w.length();
        }

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
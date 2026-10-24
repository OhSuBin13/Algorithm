import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public int[] solution(String[] gems) {
        int total = new HashSet<>(Arrays.asList(gems)).size();
        Map<String, Integer> count = new HashMap<>();

        int left = 0;
        int bestStart = 0;
        int bestLen = Integer.MAX_VALUE;

        for (int right = 0; right < gems.length; right++) {
            count.merge(gems[right], 1, Integer::sum);

            while (count.size() == total) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                String g = gems[left];
                count.put(g, count.get(g) - 1);
                if (count.get(g) == 0) count.remove(g);
                left++;
            }
        }

        return new int[]{bestStart + 1, bestStart + bestLen};
    }
}
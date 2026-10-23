
import java.util.Arrays;
import java.util.TreeMap;

class Solution {
    public int[] solution(String[] operations) {
        TreeMap<Integer, Integer> map = new TreeMap<>();

        for (String op : operations) {
            char cmd = op.charAt(0);
            int num = Integer.parseInt(op.substring(2));

            if (cmd == 'I') {
                map.merge(num, 1, Integer::sum);
            } else {
                if (map.isEmpty()) {
                    continue;
                }
                int key = (num == 1) ? map.lastKey() : map.firstKey();
                map.computeIfPresent(key, (k, v) -> v == 1 ? null : v - 1);
            }
        }

        if (map.isEmpty()) {
            return new int[] { 0, 0 };
        }
        return new int[] { map.lastKey(), map.firstKey() };
    }
}
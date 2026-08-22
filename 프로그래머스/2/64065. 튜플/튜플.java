import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public int[] solution(String s) {
        List<List<Integer>> sets = new ArrayList<>();

        String content = s.substring(1, s.length() - 1);

        String[] groups = content.split("\\},\\{");

        for (String group : groups) {
            group = group.replace("{", "")
                    .replace("}", "");

            String[] numbers = group.split(",");

            List<Integer> list = new ArrayList<>();

            for (String number : numbers) {
                list.add(Integer.parseInt(number));
            }

            sets.add(list);
        }

        sets.sort(Comparator.comparingInt(List::size));

        int[] answer = new int[sets.size()];
        Set<Integer> seen = new HashSet<>();

        int index = 0;

        for (List<Integer> set : sets) {
            for (int value : set) {
                if (!seen.contains(value)) {
                    seen.add(value);
                    answer[index++] = value;
                    break;
                }
            }
        }
        return answer;
    }
}
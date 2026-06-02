import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> answer = new ArrayList<>();
        
        int deployDay = 0;
        int count = 0;
        
        for (int i = 0; i < progresses.length; i++) {
            int remain = 100 - progresses[i];
            int day = (remain + speeds[i] - 1) / speeds[i];
            
            if (day > deployDay) {
                if (count > 0) {
                    answer.add(count);
                }
                
                deployDay = day;
                count = 1;
            } else {
                count++;
            }
        }
        answer.add(count);
        
        return answer.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}
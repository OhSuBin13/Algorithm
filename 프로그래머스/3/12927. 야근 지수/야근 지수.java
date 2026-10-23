
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int w : works) {
            pq.offer(w);
        }

        for (int i = 0; i < n; i++) {
            int max = pq.poll();
            if (max == 0) {
                return 0;
            }
            pq.offer(max - 1);
        }

        for (int w : pq) {
            answer += (long) w * w;
        }
        return answer;
    }
}
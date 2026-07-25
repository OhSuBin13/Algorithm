
import java.util.PriorityQueue;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        PriorityQueue<Integer> invincibleRounds = new PriorityQueue<>();

        long remainingSoldiers = n;

        for (int round = 0; round < enemy.length; round++) {
            invincibleRounds.offer(enemy[round]);

            if (invincibleRounds.size() > k) {
                int soldiersToUse = invincibleRounds.poll();
                remainingSoldiers -= soldiersToUse;
            }

            if (remainingSoldiers < 0) {
                return round;
            }
        }

        return enemy.length;
    }
}

import java.util.Arrays;

class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        long lo = 1;
        long hi = (long) times[times.length - 1] * n;

        while (lo < hi) {
            long mid = (lo + hi) / 2;
            long sum = 0;
            for (int t : times) {
                sum += mid / t;
                if (sum >= n) break;
            }
            if (sum >= n) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}
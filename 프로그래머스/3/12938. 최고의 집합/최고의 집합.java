import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[] solution(int n, int s) {
        List<Integer> list = new ArrayList<>();
        if (n > s)
            return new int[] { -1 };

        int base = s / n;
        int r = s % n;
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            answer[i] = (i >= n - r) ? base + 1 : base;
        }
        return answer;
    }
}
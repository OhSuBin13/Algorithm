class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int n = queue1.length;

        long sum1 = 0;
        long total = 0;

        for (int value : queue1) {
            sum1 += value;
            total += value;
        }

        for (int value : queue2) {
            total += value;
        }

        if (total % 2 != 0) {
            return -1;
        }

        long target = total / 2;

        int[] merged = new int[n * 2];

        for (int i = 0; i < n; i++) {
            merged[i] = queue1[i];
            merged[i + n] = queue2[i];
        }

        int left = 0;
        int right = n;

        int operations = 0;

        int limit = n * 3;

        while (operations <= limit) {
            if (sum1 == target) {
                return operations;
            }

            if (sum1 > target) {
                sum1 -= merged[left];
                left++;
            } else {
                sum1 += merged[right % (2 * n)];
                right++;
            }

            operations++;
        }

        return -1;
    }
}
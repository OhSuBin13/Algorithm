class Solution {
    public int[] solution(int[] sequence, int k) {
        int left = 0;
        int sum = 0;

        int bestLeft = 0;
        int bestRight = sequence.length - 1;
        int bestLength = sequence.length;

        for (int right = 0; right < sequence.length; right++) {
            sum += sequence[right];

            while (sum > k && left <= right) {
                sum -= sequence[left++];
            }

            if (sum == k) {
                int length = right - left + 1;

                if (length < bestLength) {
                    bestLength = length;
                    bestLeft = left;
                    bestRight = right;
                }
            }
        }

        return new int[]{bestLeft, bestRight};
    }
}
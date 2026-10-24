class Solution {
    private int[] stones;
    private int k;
    public int solution(int[] stones, int k) {
        int answer = 0;
        this.stones = stones;
        this.k = k;
        int left = 0, right = 200_000_000;

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canCross(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        } 
        return left;
    }

    private boolean canCross(int mid) {
        int consecutive = 0;

        for (int stone : stones) {
            if (stone < mid) consecutive++;
            else consecutive = 0;

            if (consecutive >= k) return false;
        }
        return true;
    }
}
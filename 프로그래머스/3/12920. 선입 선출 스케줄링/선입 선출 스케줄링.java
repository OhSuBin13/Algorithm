class Solution {
    public int solution(int n, int[] cores) {
        int coreCount = cores.length;

        if (n <= coreCount) {
            return n;
        }

        int left = 0;
        int right = getMax(cores) * n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (countStartedJobs(mid, cores) >= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int targetTime = left;

        int completedBefore = countStartedJobs(targetTime - 1, cores);

        for (int i = 0; i < cores.length; i++) {
            if (targetTime % cores[i] == 0) {
                completedBefore++;

                if (completedBefore == n) {
                    return i + 1;
                }
            }
        }

        return -1;
    }

    private int countStartedJobs(int time, int[] cores) {
        if (time < 0) {
            return 0;
        }

        int count = cores.length;

        for (int core : cores) {
            count += time / core;
        }

        return count;
    }

    private int getMax(int[] cores) {
        int max = 0;
        for (int core : cores) {
            max = Math.max(max, core);
        }
        return max;
    }

}
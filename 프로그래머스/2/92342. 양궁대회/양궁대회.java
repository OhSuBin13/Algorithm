class Solution {

    private int[] apeach;
    private int[] best;
    private int maxDiff = 0;

    public int[] solution(int n, int[] info) {
        apeach = info;
        best = new int[11];

        int[] ryan = new int[11];

        dfs(0, n, ryan);

        if (maxDiff == 0) {
            return new int[] { -1 };
        }

        return best;
    }

    private void dfs(int index, int remain, int[] ryan) {
        if (index == 10) {
            ryan[10] = remain;

            evaluate(ryan);

            ryan[10] = 0;
            return;
        }

        int need = apeach[index] + 1;

        if (remain >= need) {
            ryan[index] = need;
            dfs(index + 1, remain - need, ryan);
            ryan[index] = 0;
        }

        dfs(index + 1, remain, ryan);
    }

    private void evaluate(int[] ryan) {
        int ryanScore = 0;
        int apeachScore = 0;

        for (int i = 0; i < 11; i++) {
            int score = 10 - i;

            if (ryan[i] == 0 && apeach[i] == 0) {
                continue;
            }

            if (ryan[i] > apeach[i]) {
                ryanScore += score;
            } else {
                apeachScore += score;
            }
        }

        int diff = ryanScore - apeachScore;
        if (diff <= 0) {
            return;
        }

        if (diff > maxDiff) {
            maxDiff = diff;
            best = ryan.clone();
            return;
        }

        if (diff == maxDiff && isBetter(ryan, best)) {
            best = ryan.clone();
        }
    }

    private boolean isBetter(int[] candidate, int[] current) {
        for (int i = 10; i >= 0; i--) {
            if (candidate[i] > current[i]) {
                return true;
            }

            if (candidate[i] < current[i]) {
                return false;
            }
        }
        return false;
    }
}
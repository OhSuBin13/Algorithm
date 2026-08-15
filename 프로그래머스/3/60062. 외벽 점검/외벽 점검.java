class Solution {

    private int answer;
    private int[] extendedWeak;
    private int weakCount;

    public int solution(int n, int[] weak, int[] dist) {
        weakCount = weak.length;
        answer = dist.length + 1;

        extendedWeak = new int[weakCount * 2];

        for (int i = 0; i < weakCount; i++) {
            extendedWeak[i] = weak[i];
            extendedWeak[i + weakCount] = weak[i] + n;
        }

        boolean[] visited = new boolean[dist.length];
        int[] order = new int[dist.length];

        permutation(0, dist, visited, order);

        return answer > dist.length ? -1 : answer;
    }

    private void permutation(int depth, int[] dist, boolean[] visited, int[] order) {
        if (depth == dist.length) {
            check(order);
            return;
        }

        for (int i = 0; i < dist.length; i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            order[depth] = dist[i];

            permutation(depth + 1, dist, visited, order);

            visited[i] = false;
        }
    }

    private void check(int[] order) {
        for (int start = 0; start < weakCount; start++) {
            int friendIndex = 0;
            int coverage = extendedWeak[start] + order[friendIndex];

            for (int i = start; i < start + weakCount; i++) {
                if (extendedWeak[i] > coverage) {
                    friendIndex++;

                    if (friendIndex == order.length) {
                        break;
                    }

                    coverage = extendedWeak[i] + order[friendIndex];
                }
            }

            if (friendIndex < order.length) {
                answer = Math.min(answer, friendIndex + 1);
            }
        }
    }
}
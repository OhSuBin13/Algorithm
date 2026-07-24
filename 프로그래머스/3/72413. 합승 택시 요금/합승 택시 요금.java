import java.util.Arrays;

class Solution {

    private static final int INF = 100_000_000;

    public int solution(int n, int s, int a, int b, int[][] fares) {
        int[][] dist = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for (int[] fare : fares) {
            int from = fare[0];
            int to = fare[1];
            int cost = fare[2];

            dist[from][to] = cost;
            dist[to][from] = cost;
        }

        for (int mid = 1; mid <= n; mid++) {
            for (int from = 1; from <= n; from++) {
                for (int to = 1; to <= n; to++) {
                    dist[from][to] = Math.min(
                            dist[from][to],
                            dist[from][mid] + dist[mid][to]);
                }
            }
        }

        int answer = INF;

        for (int split = 1; split <= n; split++) {
            int totalCost = dist[s][split]
                    + dist[split][a]
                    + dist[split][b];

            answer = Math.min(answer, totalCost);
        }

        return answer;
    }
}
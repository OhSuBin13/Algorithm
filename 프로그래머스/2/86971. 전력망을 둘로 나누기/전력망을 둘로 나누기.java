import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<Integer>[] graph;
    private int n;
    private int answer = Integer.MAX_VALUE;

    public int solution(int n, int[][] wires) {
        this.n = n;
        graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] w : wires) {
            graph[w[0]].add(w[1]);
            graph[w[1]].add(w[0]);
        }
        dfs(1, 0);
        return answer;
    }

    private int dfs(int node, int parent) {
        int size = 1;
        for (int next : graph[node]) {
            if (next == parent)
                continue;
            int sub = dfs(next, node);
            answer = Math.min(answer, Math.abs(n - 2 * sub));
            size += sub;
        }
        return size;
    }
}
import java.util.Arrays;

class Solution {
    private int[] parent;

    public int solution(int n, int[][] costs) {
        Arrays.sort(costs, (a, b) -> Integer.compare(a[2], b[2]));
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int answer = 0;
        int edgeCount = 0;

        for (int[] c : costs) {
            // 두 섬이 연결되지 않았을 때만 다리 건설
            if (union(c[0], c[1])) {
                answer += c[2];
                edgeCount++;
                if (edgeCount == n - 1) break;
            }
        }

        return answer;
    }

    private int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    private boolean union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false;
        parent[rootB] = rootA;
        return true;
    }
}
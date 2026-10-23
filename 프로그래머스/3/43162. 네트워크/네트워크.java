class Solution {

    private int n;
    private int[][] computers;
    private boolean[] visited;

    public int solution(int n, int[][] computers) {
        this.n = n;
        this.computers = computers;
        this.visited = new boolean[n];

        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
                answer++;
            }
        }
        return answer;
    }

    private void dfs(int node) {
        visited[node] = true;

        for (int next = 0; next < n; next++) {
            if (computers[node][next] == 1 && !visited[next]) {
                dfs(next);
            }
        }
    }
}
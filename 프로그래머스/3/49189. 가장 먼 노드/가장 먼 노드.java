
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;

class Solution {
    public int solution(int n, int[][] edge) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for(int[] e : edge) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }

        int[] dist = new int[n+1];
        Arrays.fill(dist, -1);
        dist[1] = 0;

        Queue<Integer> queue = new ArrayDeque<>();
        queue.offer(1);

        int maxDist = 0;
        while(!queue.isEmpty()) {
            int cur = queue.poll();
            for (int next : graph.get(cur)) {
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    maxDist = Math.max(maxDist, dist[next]);
                    queue.offer(next);
                }
            }
        }

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == maxDist) answer++;
        }
        return answer;
    }
}
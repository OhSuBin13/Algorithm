import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class Solution {
    public int solution(int n, int[][] lighthouse) {
        List<Integer>[] graph = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
          graph[i] = new ArrayList<>();
        }

        for (int[] edge : lighthouse) {
          int a = edge[0];
          int b = edge[1];

          graph[a].add(b);
          graph[b].add(a);
        }

        // parent[node]: 트리에서 node의 부모
        int[] parent = new int[n + 1];

        // DFS 방문 순서를 저장
        int[] order = new int[n];
        int orderSize = 0;

        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(1);
        parent[1] = -1; // 루트 노드의 부모는 -1로 설정

        while (!stack.isEmpty()) {
          int current = stack.pop();
          order[orderSize++] = current;

          for (int next : graph[current]) {
            if (next == parent[current]) {
              continue; // 부모 노드로 돌아가는 경우는 무시
            }

            parent[next] = current;
            stack.push(next);
          }
        }

        /*
        * dp[node][0]: node를 켜지 않고 자식 노드들을 모두 켠 경우의 최소 등대 수
        * dp[node][1]: node를 켠 경우의 최소 등대 수
        */
        int[][] dp = new int[n + 1][2];

        // 자식부터 계산하기 위해 DFS 방문 순서를 역순으로 처리
        for (int i = n - 1; i >= 0; i--) {
          int current = order[i];

          // 현재 등대를 켜는 경우 현재 등대 1개 포함
          dp[current][1] = 1;

          for (int next : graph[current]) {
            if (parent[next] != current) {
              continue; // 부모 노드가 아닌 경우 무시
            }

            dp[current][0] += dp[next][1];

            dp[current][1] += Math.min(dp[next][0], dp[next][1]);
          } 
        }

        return Math.min(dp[1][0], dp[1][1]);
    }
}
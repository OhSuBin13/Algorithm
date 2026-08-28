
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
  public long solution(int[] a, int[][] edges) {
    int n = a.length;

    long[] weight = new long[n];
    long total = 0;

    for (int i = 0; i < n; i++) {
      weight[i] = a[i];
      total += a[i];
    }

    if (total != 0) {
      return -1;
    }

    List<Integer>[] graph = new ArrayList[n];

    for (int i = 0; i < n; i++) {
      graph[i] = new ArrayList<>();
    }

    for (int[] edge : edges) {
      int u = edge[0];
      int v = edge[1];

      graph[u].add(v);
      graph[v].add(u);
    }

    int[] parent = new int[n];
    Arrays.fill(parent, -1);

    int[] order = new int[n];

    int[] stack = new int[n];
    int stackSize = 0;
    int orderSize = 0;

    stack[stackSize++] = 0;
    parent[0] = 0;

    while (stackSize > 0) {
      int current = stack[--stackSize];

      order[orderSize++] = current;

      for (int next : graph[current]) {
        if (parent[next] != -1) {
          continue;
        }

        parent[next] = current;
        stack[stackSize++] = next;
      }
    }

    long answer = 0;

    for (int i = n - 1; i > 0; i--) {
      int current = order[i];
      int p = parent[current];

      answer += Math.abs(weight[current]);
      weight[p] += weight[current];
    }

    return answer;
  }
}
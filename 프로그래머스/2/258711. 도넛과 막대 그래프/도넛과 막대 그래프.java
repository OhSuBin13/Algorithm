class Solution {
  public int[] solution(int[][] edges) {
    int maxVertex = 0;

    for (int[] edge : edges) {
      maxVertex = Math.max(maxVertex, edge[0]);
      maxVertex = Math.max(maxVertex, edge[1]);
    }

    int[] inDegree = new int[maxVertex + 1];
    int[] outDegree = new int[maxVertex + 1];
    boolean[] exists = new boolean[maxVertex + 1];

    for (int[] edge : edges) {
      int from = edge[0];
      int to = edge[1];

      outDegree[from]++;
      inDegree[to]++;

      exists[from] = true;
      exists[to] = true;
    }

    int createdVertex = 0;

    for (int vertex = 1; vertex <= maxVertex; vertex++) {
      if (inDegree[vertex] == 0 && outDegree[vertex] >= 2) {
        createdVertex = vertex;
        break;
      }
    }

    int barCount = 0;
    int eightCount = 0;

    for (int vertex = 1; vertex <= maxVertex; vertex++) {
      if (vertex == createdVertex || !exists[vertex]) {
        continue;
      }

      if (outDegree[vertex] == 0) {
        barCount++;
      }

      if (inDegree[vertex] >= 2 && outDegree[vertex] == 2) {
        eightCount++;
      }
    }

    int totalGraphCount = outDegree[createdVertex];
    int donutCount = totalGraphCount - barCount - eightCount;

    return new int[] {
        createdVertex,
        donutCount,
        barCount,
        eightCount
    };
  }
}
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Solution {

  static class Edge {
    int to;
    int cost;

    Edge(int to, int cost) {
      this.to = to;
      this.cost = cost;
    }
  }

  static class Node implements Comparable<Node> {
    int village;
    int dist;

    Node(int village, int dist) {
      this.village = village;
      this.dist = dist;
    }

    @Override
    public int compareTo(Node other) {
      return Integer.compare(this.dist, other.dist);
    }
  }

  public int solution(int N, int[][] road, int K) {
    List<Edge>[] graph = new ArrayList[N + 1];

    for (int i = 1; i <= N; i++) {
      graph[i] = new ArrayList<>();
    }

    for (int[] r : road) {
      int a = r[0];
      int b = r[1];
      int cost = r[2];

      graph[a].add(new Edge(b, cost));
      graph[b].add(new Edge(a, cost));
    }

    int[] dist = new int[N + 1];
    Arrays.fill(dist, Integer.MAX_VALUE);

    PriorityQueue<Node> pq = new PriorityQueue<>();

    dist[1] = 0;
    pq.offer(new Node(1, 0));

    while (!pq.isEmpty()) {
      Node current = pq.poll();

      int now = current.village;
      int currentDist = current.dist;

      if (currentDist > dist[now]) {
        continue;
      }

      for (Edge edge : graph[now]) {
        int next = edge.to;
        int nextDist = currentDist + edge.cost;

        if (nextDist < dist[next]) {
          dist[next] = nextDist;
          pq.offer(new Node(next, nextDist));
        }
      }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
      if (dist[i] <= K) {
        answer++;
      }
    }

    return answer;
  }
}
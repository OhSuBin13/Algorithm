#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> graph;
bool visited[101];

int dfs(int node) {
    visited[node] = true;
    int cnt = 1;

    for (int nxt : graph[node]) {
        if (!visited[nxt])
            cnt += dfs(nxt);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;

    for (int i = 0; i < wires.size(); i++) {
        graph.assign(n + 1, vector<int>());
        memset(visited, false, sizeof(visited));

        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int group1 = dfs(1);
        int group2 = n - group1;

        answer = min(answer, abs(group1 - group2));
    }
    return answer;
}
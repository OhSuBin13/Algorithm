#include <string>
#include <vector>
#include <queue>
#include <iostream> 
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

int solution(int n, vector<vector<int>> costs) {
    /*
    costs[i][0], costs[i][1] : 다리가 연결된 두 섬의 번호, costs[i][2] : 건설 비용
    return : 모든 섬이 서로 연결된 최소 비용
    */
    int answer = 0;
    vector<vector<pii>> bridge(n); // {섬 B, cost}
    int dist[100];
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int,pii>>> pq; // {cost, {섬 A, 섬 B}}

    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < costs.size(); i++) {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        bridge[a].push_back({ b, cost });
        bridge[b].push_back({ a, cost });
    }
    dist[0] = 0;
    for (int i = 0; i < bridge[0].size(); i++) {
        pq.push({ bridge[0][i].second, {0, bridge[0][i].first} });
    }
    while (!pq.empty()) {
        pair<int, pii> tmp = pq.top();
        pq.pop();
        int cost = tmp.first;
        int a = tmp.second.first;
        int b = tmp.second.second;
        if (dist[a] != -1 && dist[b] != -1) continue;
        if (dist[a] != -1) {
            dist[b] = dist[a] + cost;
            answer += cost;
            for (int i = 0; i < bridge[b].size(); i++) {
                pq.push({ bridge[b][i].second, {b, bridge[b][i].first} });
            }
        }
        else {
            dist[a] = dist[b] + cost;
            answer += cost;
            for (int i = 0; i < bridge[a].size(); i++) {
                pq.push({ bridge[a][i].second, {a, bridge[a][i].first} });
            }
        }
    }
    return answer;
}
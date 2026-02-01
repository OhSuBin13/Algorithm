#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MAX 20001
#define INF 50001
using namespace std;

int node[MAX];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {dist, dst}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxNum = 0;
    for (int i = 1; i <= n; i++) {
        node[i] = INF;
    }
    vector<vector<int>> v(n+1);
    for (int i = 0; i < edge.size(); i++) {
        int src = edge[i][0];
        int dst = edge[i][1];
        v[src].push_back(dst);
        v[dst].push_back(src);
    }
    pq.push(make_pair(0, 1));
    node[1] = 0;

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curDst = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < v[curDst].size(); i++) {
            int nextDist = curDist + 1;
            int nextDst = v[curDst][i];
            if (node[nextDst] <= nextDist) continue;
            if (maxNum < nextDist) maxNum = nextDist;
            node[nextDst] = nextDist;
            pq.push(make_pair(nextDist, nextDst));
        }
    }

    for (int i = 1; i <= n; i++) {
        if (maxNum == node[i]) answer++;
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<pair<string, bool>>> m;
vector<string> answer;
int ticketSize;
bool found = false;

void dfs(int n, vector<string> s) {
    if (found) return;
    if (n == ticketSize) {
        answer = s;
        found = true;
        return;
    }
    string curPos = s[s.size() - 1];
    vector<pair<string, bool>>& arrive = m[curPos];
    for (int i = 0; i < arrive.size(); i++) {
        string nextPos = arrive[i].first;
        bool isVisited = arrive[i].second;
        if (isVisited) continue;
        arrive[i].second = true;
        s.push_back(nextPos);
        dfs(n + 1, s);
        s.pop_back();
        arrive[i].second = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    ticketSize = tickets.size();
    for (int i = 0; i < ticketSize; i++) {
        m[tickets[i][0]].push_back(make_pair(tickets[i][1], false));
    }
    for (int i = 0; i < ticketSize; i++) {
        sort(m[tickets[i][0]].begin(), m[tickets[i][0]].end());
    }
    vector<string> airport;
    airport.push_back("ICN");
    dfs(0, airport);
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> sortedPriorities = priorities;
    sort(sortedPriorities.begin(), sortedPriorities.end(), compare);
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
    }

    while (!q.empty()) {
        int cur = q.front().first;
        int rank = q.front().second;
        q.pop();
        if (rank == sortedPriorities[0]) {
            answer++;
            sortedPriorities.erase(sortedPriorities.begin());
            if (cur == location) break;
        }
        else {
            q.push({ cur,rank });
        }
    }

    return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curWeight = 0;
    queue<pair<int,int>> q;

    while (!q.empty() || !truck_weights.empty()) {
        answer++;

        if (answer >= q.front().second) {
            curWeight -= q.front().first;
            q.pop();
        }
        if (!truck_weights.empty() && curWeight + truck_weights.front() <= weight && q.size() + 1 <= bridge_length) {
            q.push(make_pair(truck_weights.front(), answer + bridge_length));
            curWeight += truck_weights.front();
            truck_weights.erase(truck_weights.begin());
        }
    }


    return answer;
}
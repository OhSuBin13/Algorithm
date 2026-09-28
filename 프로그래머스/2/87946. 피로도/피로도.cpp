#include <string>
#include <vector>
using namespace std;
struct User
{
    int hp;
};

void dfs(int& ans, int cnt, User user, vector<vector<int>> dungeons, vector<bool> visited) {
    if (cnt == dungeons.size()) {
        ans = cnt;
        return;
    }
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i]) continue;
        if (dungeons[i][0] > user.hp) continue;

        visited[i] = true;
        User newUser = { user.hp - dungeons[i][1]};
        dfs(ans, cnt + 1, newUser, dungeons, visited);
        visited[i] = false;
    }

    ans = max(ans, cnt);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    User user = { k };
    vector<bool> visited(dungeons.size());
    dfs(answer, 0, user, dungeons, visited);
    return answer;
}
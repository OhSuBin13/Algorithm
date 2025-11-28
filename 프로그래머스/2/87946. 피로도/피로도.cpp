#include <string>
#include <vector>

using namespace std;

bool visited[8];

int dfs(int size, int curStamina, vector<vector<int>> dungeons) {
    bool flag = true;
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] || curStamina < dungeons[i][0]) continue;
        flag = false;
    }
    if (flag) return size;
    int ans = 0;
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] || curStamina < dungeons[i][0]) continue;
        visited[i] = true;
        ans = max(ans, dfs(size + 1, curStamina - dungeons[i][1], dungeons));
        visited[i] = false;
    }
    return ans;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    answer = dfs(0, k, dungeons);
    return answer;
}
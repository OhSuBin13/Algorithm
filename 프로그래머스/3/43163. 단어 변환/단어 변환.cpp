#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q;
    for (int i = 0; i < words.size(); i++) {
        if (target == words[i]) break;
        if (i == words.size() - 1) return 0;
    }
    q.push({ begin, 0 });
    
    while (!q.empty()) {
        string curWord = q.front().first;
        int changeNum = q.front().second;
        int tmp = 0;
        for (int i = 0; i < target.size(); i++) {
            if (tmp > 1) break;
            if (target[i] != curWord[i]) tmp++;
            if (i == curWord.size() - 1 && tmp == 1) return changeNum + 1;
        }
        q.pop();

        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;
            int tmp = 0;
            for (int j = 0; j < curWord.size(); j++) {
                if (tmp > 1) break;
                if (curWord[j] != words[i][j]) tmp++;
                if (j == curWord.size() - 1 && tmp == 1) {
                    visited[i] = true;
                    q.push({ words[i], changeNum + 1 });
                }
            }
        }
    }
    
    return answer;
}
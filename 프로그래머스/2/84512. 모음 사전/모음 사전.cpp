#include <string>
#include <vector>
using namespace std;

vector<string> dictionary;
char spellList[5] = { 'A', 'E', 'I', 'O', 'U' };

void dfs(int cnt, string spell) {
    dictionary.push_back(spell);
    if (cnt == 5) return;
    
    for (int i = 0; i < 5; i++) {
        dfs(cnt + 1, spell + spellList[i]);
    }
}
int solution(string word) {
    int answer = 0;
    dfs(0, "");
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i] == word) {
            answer = i;
            break;
        }
    }
    return answer;
}
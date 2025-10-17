#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for (int i = 0; i < completion.size(); i++) {
        if (m.find(completion[i]) == m.end()) {
            m[completion[i]] = 1;
        }
        else m[completion[i]]++;
    }
    for (int i = 0; i < participant.size(); i++) {
        if (m.find(participant[i]) == m.end()) {
            answer = participant[i];
            break;
        }
        else {
            if (m[participant[i]] == 0) {
                answer = participant[i];
                break;
            }
            m[participant[i]]--;
        }
    }
    return answer;
}
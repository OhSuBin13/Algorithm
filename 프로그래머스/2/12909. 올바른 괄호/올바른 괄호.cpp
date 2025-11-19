#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> bracket;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            if (!bracket.empty()) bracket.pop();
            else {
                answer = false;
                break;
            }
        }
        else {
            bracket.push(s[i]);
        }
    }
    if (!bracket.empty()) answer = false;
    return answer;
}
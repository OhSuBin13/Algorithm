#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> tmp;
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (s[i] == '(') tmp.push('(');
        else {
            if (tmp.empty()) return false;
            else tmp.pop();
        }
    }
    if (!tmp.empty()) return false;
    return answer;
}
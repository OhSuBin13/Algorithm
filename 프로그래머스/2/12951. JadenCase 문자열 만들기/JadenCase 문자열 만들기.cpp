#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return tolower(c);
        });
    for (int i = 0; i < s.length(); i++) {
        if((i == 0 || s[i - 1] == ' ') && 'a' <= s[i] && s[i] <= 'z') {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}
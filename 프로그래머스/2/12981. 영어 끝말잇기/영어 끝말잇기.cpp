#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    string tmp = words[0];
    s.insert(words[0]);

    for (int i = 1; i < words.size(); i++) {
        if (tmp[tmp.length() - 1] != words[i][0]) return { i % n + 1, (i + n) / n };
        tmp = words[i];
        if (s.find(words[i]) != s.end()) return { i % n + 1,(i + n) / n };
        s.insert(words[i]);
    }

    return { 0, 0 };
}
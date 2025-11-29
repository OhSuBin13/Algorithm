#include <string>
#include <vector>
#include <iostream>
using namespace std;

int calculateUpDown(char c) {
    return min(c - 'A', 'Z' - c + 1);
}

int solution(string name) {
    int answer = 0;
    int n = name.length();

    for (char c : name) {
        answer += calculateUpDown(c);
    }

    int move = n - 1;

    for (int i = 0; i < n; i++) {
        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++;
        }

        move = min(move, i * 2 + (n - next));

        move = min(move, (n - next) * 2 + i);
    }
    answer += move;
    return answer;
}
//A:65, Z:90

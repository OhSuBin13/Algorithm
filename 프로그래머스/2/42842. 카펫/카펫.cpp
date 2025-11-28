#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i != 0) continue;

        int a = i, b = yellow / i;
        if (2 * a + 2 * b + 4 != brown) continue;

        (a >= b) ? answer.insert(answer.end(), { a + 2, b + 2 }) : answer.insert(answer.end(), { b + 2, a + 2 });
        break;
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (int i = 0; i < number.length(); i++) {
        while (!answer.empty() && answer.back() < number[i] && k > 0) {
            k--;
            answer.pop_back();
        }

        answer.push_back(number[i]);
    }
    if (k > 0) {
        answer = answer.substr(0, answer.length() - k);
    }
    return answer;
}
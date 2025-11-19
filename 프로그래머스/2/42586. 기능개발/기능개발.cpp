#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> deploy;
    for (int i = progresses.size() - 1; i >= 0; i--) {
        int day = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) day++;
        deploy.push(day);
    }
    int tmp = 1;
    int top;

    for (int i = 0; i < progresses.size() - 1; i++) {
        top = deploy.top();
        deploy.pop();

        if (deploy.top() > top) {
            answer.push_back(tmp);
            tmp = 1;
        }
        else {
            deploy.pop();
            deploy.push(top);
            tmp++;
        }
    }
    answer.push_back(tmp);
    
    return answer;
}
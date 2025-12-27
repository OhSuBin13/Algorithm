#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> s; // price, time
    int tmp[100000];
    for (int i = 0; i < prices.size(); i++) {
        int price = prices[i];
        while (!s.empty() && s.top().first > price) {
            tmp[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push(make_pair(price, i));
    }
    while (!s.empty()) {
        tmp[s.top().second] = prices.size() - 1 - s.top().second;
        s.pop();
    }
    for (int i = 0; i < prices.size(); i++) {
        answer.push_back(tmp[i]);
    }
    return answer;
}
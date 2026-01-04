#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    map<int, int> m;
    int heapSize = 0;
    for (auto& command : operations) {
        int num = stoi(command.substr(2));
        if (command[0] == 'I') {
            m[num]++;
            minHeap.push(num);
            maxHeap.push(num);
            heapSize++;
        }
        else {
            if (!heapSize) continue;
            if (num < 0) {
                while (!minHeap.empty() &&  m[minHeap.top()] == 0) {
                    minHeap.pop();
                }
                if (!minHeap.empty()) {
                    m[minHeap.top()]--;
                    minHeap.pop();
                    heapSize--;
                }
            }
            else {
                while (!maxHeap.empty() && m[maxHeap.top()] == 0) {
                    maxHeap.pop();
                }
                if (!maxHeap.empty()) {
                    m[maxHeap.top()]--;
                    maxHeap.pop();
                    heapSize--;
                }
            }
        }
    }
    if (!heapSize) {
        return { 0, 0 };
    }
    while (!maxHeap.empty() && m[maxHeap.top()] == 0) maxHeap.pop();
    while (!minHeap.empty() && m[minHeap.top()] == 0) minHeap.pop();
    answer.push_back(maxHeap.top());
    answer.push_back(minHeap.top());
    return answer;
}
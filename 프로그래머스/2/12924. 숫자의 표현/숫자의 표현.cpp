#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int left = 1, right = 1;
    int sum = 1;
    while (right <= n) {
        if (sum == n) {
            answer++;
            sum -= left;
            left++;
        }
        else if (sum < n) {
            sum += ++right;
        }
        else {
            sum -= left++;
        }
    }
    return answer;
}
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int lossNum = lost.size();

    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                reserve[i] = -1;
                lost[j] = -1;
                lossNum--;
                break;
            }
        }
    }

    answer = n - lossNum;

    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i] == -1) continue;
        int frontStudent = reserve[i] - 1;
        int backStudent = reserve[i] + 1;
        for (int j = 0; j < lost.size(); j++) {
            if (frontStudent == lost[j]) {
                answer++;
                lost[j] = -1;
                break;
            }
            else if (backStudent == lost[j]) {
                answer++;
                lost[j] = -1;
                break;
            }
        }
    }
    return answer;
}
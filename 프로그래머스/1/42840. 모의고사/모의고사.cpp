#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int first[5]  = { 1, 2, 3, 4, 5 };
    int second[8]  = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int third[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int cnt[3] = { 0, 0, 0 };
    for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == first[i % 5]) cnt[0]++;
		if (answers[i] == second[i % 8]) cnt[1]++;
		if (answers[i] == third[i % 10]) cnt[2]++;
    }
    int maxCnt = 0;
    for (int i = 0; i < 3; i++) {
        if (cnt[i] > maxCnt) {
            maxCnt = cnt[i];
        }
    }
    for(int i = 0; i < 3; i++) {
        if (cnt[i] == maxCnt) {
            answer.push_back(i + 1);
        }
	}
    return answer;
}
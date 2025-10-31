#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxNum = 0;
    for (int i = 0; i < sizes.size(); i++) {
        for (int j = 0; j < sizes[i].size(); j++) {
            if (sizes[i][j] > maxNum) {
				maxNum = sizes[i][j];
            }
        }
    }
	int secondMaxNum = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) {
			swap(sizes[i][0], sizes[i][1]);
        }
        if (secondMaxNum < sizes[i][1]) {
            secondMaxNum = sizes[i][1];
        }
    }
	answer = maxNum * secondMaxNum;
    return answer;
}
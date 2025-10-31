#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++) {
        int start = commands[i][0] - 1;
        int end = commands[i][1];
        int k = commands[i][2] - 1;
        
        vector<int> subarray(array.begin() + start, array.begin() + end);
        sort(subarray.begin(), subarray.end());
        
        answer.push_back(subarray[k]);
	}
    return answer;
}
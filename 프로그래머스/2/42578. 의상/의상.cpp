#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    unordered_map<string, int> type_count;
    for (auto& item : clothes) {
        type_count[item[1]]++;
    }
    answer = 1;
    for (auto& type : type_count) {
		answer *= (type.second + 1);
    }
	answer -= 1;
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

	// Create a map to count the number of clothes for each type
	unordered_map<string, int> type_count;
	for (const auto& item : clothes) {
		type_count[item[1]]++;
	}

	// Calculate the number of combinations
	int combinations = 1;
	for (const auto& pair : type_count) {
		combinations *= (pair.second + 1);
	}
	answer = combinations - 1; // Subtract the case where no clothes are worn

    return answer;
}
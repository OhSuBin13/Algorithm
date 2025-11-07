#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> phone_map;
    for (const auto& phone_number : phone_book) {
		phone_map[phone_number]++;
	}
    for (const auto& phone_number : phone_book) {
        string prefix;
        for (size_t i = 0; i < phone_number.length() - 1; ++i) {
            prefix += phone_number[i];
            if (phone_map.find(prefix) != phone_map.end()) {
                answer = false;
                return answer;
            }
        }
	}

    return answer;
}
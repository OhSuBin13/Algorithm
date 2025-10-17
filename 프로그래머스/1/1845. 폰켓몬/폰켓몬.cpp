#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, bool> m;
    int pType = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums[i]) == m.end()) {
            m[nums[i]] = true;
            pType++;
        }
    }
    if (pType >= nums.size() / 2) answer = nums.size() / 2;
    else answer = pType;
    return answer;
}
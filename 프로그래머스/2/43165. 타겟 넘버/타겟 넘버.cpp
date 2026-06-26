#include <string>
#include <vector>

using namespace std;

int dfs(int idx, int sum, int target, const vector<int>& numbers) {
    if (idx == numbers.size()) {
        return sum == target ? 1 : 0;
    }

    return dfs(idx + 1, sum + numbers[idx], target, numbers)
        + dfs(idx + 1, sum - numbers[idx], target, numbers);
}

int solution(vector<int> numbers, int target) {
    return dfs(0, 0, target, numbers);
}
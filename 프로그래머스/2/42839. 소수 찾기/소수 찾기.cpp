#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

set<int> nums;
vector<bool> visited(7);

void dfs(string& numbers, string current) {
    if (!current.empty()) {
        nums.insert(stoi(current));
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(numbers, current + numbers[i]);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    dfs(numbers, "");
    for (int n : nums) {
        if (isPrime(n)) answer++;
    }
    
    return answer;
}
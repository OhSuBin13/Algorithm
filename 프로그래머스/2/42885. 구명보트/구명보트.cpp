#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;
    int answer = 0;

    while (left <= right) {
        if (left != right && people[left] + people[right] <= limit) {
            left++;
        }

        right--;
        answer++;
    }
    return answer;
}

int main() {
    solution({ 70,50,50,80 }, 100);
    return 0;
}
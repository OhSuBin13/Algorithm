#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> v(10001);
    for (int i = 0; i < citations.size(); i++) {
        for (int j = citations[i]; j >= 0; j--) {
            v[j]++;
        }
    }
    for (int i = 10000; i >= 0; i--) {
        if (v[i] >= i) return i;
    }
    return answer;
}
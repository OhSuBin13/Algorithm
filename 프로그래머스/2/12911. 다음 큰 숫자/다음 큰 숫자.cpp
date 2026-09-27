#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int to_binary_one_cnt(int n) {
    string tmp = "";
    while (n) {
        tmp += n % 2 + '0';
        n /= 2;
    }
    int ans = 0;
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == '1') ans++;
    }

    return ans;
}

int solution(int n) {
    int answer = n + 1;
    int num = to_binary_one_cnt(n);
    while (1) {
        if (num == to_binary_one_cnt(answer)) return answer;
        answer++;
    }
    return answer;
}
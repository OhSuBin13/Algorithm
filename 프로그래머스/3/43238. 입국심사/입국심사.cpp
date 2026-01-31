#include <string>
#include <vector>
#include <iostream>
#define MAX 1000000000000000000
typedef long long ll;
using namespace std;

long long solution(int n, vector<int> times) {
    ll answer = 0;
    ll src = 0, dst = MAX;

    while (src < dst) {
        ll mid = (src + dst) / 2;
        ll num = 0;
        for (int i = 0; i < times.size(); i++) {
            num += mid / times[i];
        }
        
        if (num < n) {
            src = mid + 1;
        }
        else if (num >= n) {
            answer = mid;
            dst = mid;
        }
    }
    
    return answer;
}
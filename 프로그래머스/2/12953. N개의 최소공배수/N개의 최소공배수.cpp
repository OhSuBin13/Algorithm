#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
int solution(vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    int tmp = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int num = tmp * arr[i];
        int common = gcd(tmp, arr[i]);
        tmp = num / common;
    }
    return tmp;
}
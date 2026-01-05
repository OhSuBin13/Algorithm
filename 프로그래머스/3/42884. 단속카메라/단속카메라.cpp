#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    /*
    routes[i][0]: i번째 차량 진입 지점, routes[i][1] : i번째 차량 나간 지점
    return : 모든 차량을 단속하는 최소 설치 카메라 수
    */
    int answer = 0;
    int pos = -40000;
    sort(routes.begin(), routes.end(), cmp);
    for (int i = 0; i < routes.size(); i++) {
        if (pos < routes[i][0]) {
            pos = routes[i][1];
            answer++;
        }
    }
    return answer;
}
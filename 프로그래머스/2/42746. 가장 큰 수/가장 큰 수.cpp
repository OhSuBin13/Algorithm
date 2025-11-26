#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 정렬 기준 함수
bool compare(const string &a, const string &b) {
    // 두 문자열을 합쳤을 때 더 큰 쪽이 우선순위를 가짐
    // 예: "3", "30" -> "330" > "303" 이므로 true ("3"이 먼저 옴)
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNums;

    // 1. int를 string으로 변환하여 저장
    for (int num : numbers) {
        strNums.push_back(to_string(num));
    }

    // 2. 커스텀 정렬 수행
    sort(strNums.begin(), strNums.end(), compare);

    // 3. 정렬된 문자열 이어 붙이기
    for (const string &s : strNums) {
        answer += s;
    }

    // 예외 처리: 모든 숫자가 0인 경우 (예: [0, 0, 0] -> "000"이 아닌 "0"이어야 함)
    if (answer[0] == '0') return "0";

    return answer;
}
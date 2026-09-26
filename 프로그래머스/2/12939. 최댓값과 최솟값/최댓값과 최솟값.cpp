#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> split(string s, string delimiter) {
    vector<int> ret;
    int idx;
    while ((idx = s.find(delimiter)) != string::npos) {
        ret.push_back(stoi(s.substr(0, idx)));
        s.erase(0, idx + delimiter.length());
    }
    ret.push_back(stoi(s));
    return ret;
}

string solution(string s) {
    string answer = "";
    vector<int> v = split(s, " ");
    int maxNum = *max_element(v.begin(), v.end());
    int minNum = *min_element(v.begin(), v.end());
    answer = to_string(minNum) + " " + to_string(maxNum);
    return answer;
}

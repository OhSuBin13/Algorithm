#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int numOfPaper = citations.size();
    int quotation = 0;

    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
        quotation = citations[i];
        if (quotation <= numOfPaper) {
            answer = quotation;
        }
        else answer = max(answer, numOfPaper);
        numOfPaper--;
    }
    return answer;
}
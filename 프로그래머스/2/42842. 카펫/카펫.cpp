#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    for (int height = 3; height * height <= total; height++) {
        if (total % height != 0) continue;
        int width = total / height;

        if ((width - 2) * (height - 2) == yellow) {
            return { width, height };
        }
    }
    return answer;
}
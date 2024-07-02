#include <iostream>
#include <algorithm>
using namespace std;

constexpr size_t MAX_NUM = 100000;

struct Title {
    int num;
    string name;
};

Title titles[MAX_NUM];
int target;

Title binarySearch(int val, int first, int last);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, num;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> titles[i].name >> titles[i].num;
    }

    for (int i = 0; i < M; i++) {
        cin >> num;
        Title result = binarySearch(num, 0, N - 1);
        cout << result.name << "\n";
    }

    return 0;
}

Title binarySearch(int num, int first, int last) {
    if (first <= last) {
        int mid = (first + last) / 2;
        if (num <= titles[mid].num) return binarySearch(num, first, mid - 1);
        else return binarySearch(num, mid + 1, last);
    }
    else return titles[first];
}
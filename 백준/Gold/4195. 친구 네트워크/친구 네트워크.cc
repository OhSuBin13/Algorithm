#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> parent;
map<string, int> friendNum;

// 루트 노드를 찾는 함수 (경로 압축 적용)
string find(string x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

// 두 집합을 병합하는 함수 (유니온 바이 사이즈 적용)
void unionSets(string x, string y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        // 항상 큰 네트워크가 루트가 되도록 병합
        if (friendNum[x] < friendNum[y]) {
            swap(x, y);
        }
        parent[y] = x; // y를 x에 병합
        friendNum[x] += friendNum[y];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int F;
        cin >> F;

        parent.clear();
        friendNum.clear();

        for (int j = 0; j < F; j++) {
            string friendA, friendB;
            cin >> friendA >> friendB;

            // 처음 등장한 친구에 대해 초기화
            if (parent.find(friendA) == parent.end()) {
                parent[friendA] = friendA;
                friendNum[friendA] = 1;
            }
            if (parent.find(friendB) == parent.end()) {
                parent[friendB] = friendB;
                friendNum[friendB] = 1;
            }

            // 친구 네트워크 병합
            unionSets(friendA, friendB);

            // 루트 노드의 네트워크 크기 출력
            cout << friendNum[find(friendA)] << "\n";
        }
    }

    return 0;
}
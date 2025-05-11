#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

// A→B→C 방향의 교차곱 (양수: 반시계, 음수: 시계)
ll orient(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y)
         - (B.y - A.y) * (C.x - A.x);
}

// P가 △ABC의 내부에 있는지 검사 (strictly inside)
bool insideTriangle(const Point &A, const Point &B, const Point &C, const Point &P) {
    ll o1 = orient(A, B, P);
    ll o2 = orient(B, C, P);
    ll o3 = orient(C, A, P);
    return (o1 > 0 && o2 > 0 && o3 > 0) 
        || (o1 < 0 && o2 < 0 && o3 < 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Point> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    ll answer = 0;
    // 모든 4-점 조합
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                for (int l = k+1; l < N; l++) {
                    bool concave = false;
                    // 네 점 중 하나가 나머지 세 점의 삼각형 내부에 있는지 검사
                    if      (insideTriangle(pts[j], pts[k], pts[l], pts[i])) concave = true;
                    else if (insideTriangle(pts[i], pts[k], pts[l], pts[j])) concave = true;
                    else if (insideTriangle(pts[i], pts[j], pts[l], pts[k])) concave = true;
                    else if (insideTriangle(pts[i], pts[j], pts[k], pts[l])) concave = true;

                    if (!concave) answer++;
                }
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
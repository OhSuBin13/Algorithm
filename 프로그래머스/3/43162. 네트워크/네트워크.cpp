#include <vector>
#include <unordered_set>
using namespace std;

int parent[200];

int findParent(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) {
        parent[b] = a;
    }
    else if (a > b) parent[a] = b;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {
                unionParent(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        s.insert(findParent(i));
    }
    answer = s.size();
    return answer;
}
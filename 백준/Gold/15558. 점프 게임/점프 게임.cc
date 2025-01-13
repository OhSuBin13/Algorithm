#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
 
using namespace std;
 
int map[2][200000];
bool check[2][200000];
 
int main() {
    
    //freopen("Text.txt", "r", stdin);
 
    memset(map, 1, sizeof(map));
 
    int n, k;
    cin >> n >> k;
 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
 
    queue < tuple<int, int, int>>q;
 
    q.push({ 0,0,0 });
    check[0][0] = true;
 
    while (!q.empty()) {
        int line, x, sec;
        tie(line, x, sec) = q.front();
        q.pop();
    
 
        //나갔나 안나갔나 체크
        if (x >= n) {
            cout << 1 << endl;
            return 0;
        }
 
        //case 1
        if (map[line][x + 1] != 0 && check[line][x + 1] == false) {
            check[line][x + 1] = true;
            q.push({ line,x + 1,sec + 1 });
        }
        //case 2
        if (x-1>sec && map[line][x - 1] != 0 && check[line][x - 1] == false) {
            check[line][x - 1] = true;
            q.push({ line,x - 1,sec + 1 });
        }
        //case3
        if (line == 0) {
            if (map[1][x + k] != 0 && check[1][x + k] == false) {
                check[1][x + k] = true;
                q.push({ 1,x + k,sec + 1 });
            }
        }
        if (line == 1) {
            if (map[0][x + k] != 0 && check[0][x + k] == false) {
                check[0][x + k] = true;
                q.push({ 0,x + k,sec + 1 });
            }
        }
    }
 
 
    cout << 0 << endl;
}

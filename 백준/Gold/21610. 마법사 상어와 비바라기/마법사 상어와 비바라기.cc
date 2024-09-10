#include <iostream>
#include <vector>
#include <queue> // 구름 위치
#include <utility> //pair
using namespace std;

int N, M; // 맵 크기, 이동 수
int map[51][51]; // 맵
int di, si; // 이동 정보 - 방향, 거리

queue<pair<int, int>> q; // r, c

// 방향 : ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[9] = {99, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {99, 0, -1, -1, -1, 0, 1, 1, 1};

int main(){
  scanf("%d %d", &N, &M); // 맵 크기, 구름 이동 수

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &map[i][j]); // 맵 입력 받기
    }
  }
  
  // 처음 비바라기 구름 위치 넣기
  q.push({N, 1});
  q.push({N, 2});
  q.push({N-1, 1});
  q.push({N-1, 2});

  for(int i = 0; i < M; i++){ // while(M--) 가 더 편해보이는군
    bool visited[51][51] = {false}; // 구름 체크
    vector<pair<int, int>> v; // 구름 좌표

    scanf("%d %d", &di, &si); // 이동 정보 입력받기

    int size = q.size(); // 큐 크기

    for(int j = 0; j < size; j++){
      // 좌표 꺼내기
      int r = q.front().first;
      int c = q.front().second;

      // 3. 구름이 모두 사라진다.
      q.pop();

      //1. 모든 구름 이동
      for(int k = 0; k < si; k++){
        r += dy[di];
        c += dx[di];

        // 범위 넘어갈 때
        if(r < 1){
          r = N;
        }
        if(r > N){
          r = 1;
        }
        if(c < 1){
          c = N;
        }
        if(c > N){
          c = 1;
        }
      }
      
      //2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
      map[r][c]++;
      visited[r][c] = true; // 구름 있는 칸 체크
      v.push_back({r, c}); // 구름 좌표 재저장
    }

    //4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전
    for(int j = 0; j < size; j++){
      int r = v[j].first;
      int c = v[j].second;
      // 대각선 2, 4, 6, 8 방향
      for(int k = 2; k <= 9; k += 2){
        // 대각선 위치 체크
        int nr = r + dy[k];
        int nc = c + dx[k];
        
        // 범위 벗어나지 않고 대각선 방향 물이 있는 경우
        if(nr <= N && nc <= N && nr >= 1 && nc >= 1 && map[nr][nc]){
          map[r][c]++;
        }
      }
    }

    //5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름
    for(int j = 1; j <= N; j++){
      for(int k = 1; k <= N; k++){
        //구름이 있었던 칸 제외
        if(map[j][k] >= 2 && !visited[j][k]){
          // 구름 생성
          q.push({j, k});
          map[j][k] -= 2; //구름 생기면 물의 양 2만큼 감소
        } else {
        }
      }
    }
  }
  
  int cnt = 0;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(map[i][j] > 0){
        cnt += map[i][j];
      }
    }
  }

  printf("%d", cnt);
  return 0;
}
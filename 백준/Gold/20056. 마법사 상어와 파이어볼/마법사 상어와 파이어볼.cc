#include <iostream>
#include <vector>
#include <cmath>
#define MAX 51

using namespace std;

struct Ball{
    int m,s,d;
};
int N,M,K;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

vector<Ball> fireBall[MAX][MAX];

void moveBall()
{
    vector<Ball> tmpBall[MAX][MAX];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<fireBall[i][j].size();k++){
                int s= fireBall[i][j][k].s%N;
                int d= fireBall[i][j][k].d;
                
                int nx = i+dx[d]*s;
                int ny = j+dy[d]*s;
                
                
                if(nx < 1)   nx+=N;
                if(nx > N) nx -=N;
                
                if(ny < 1)   ny+=N;
                if(ny > N) ny-= N;
                
                tmpBall[nx][ny].push_back(fireBall[i][j][k]);
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            fireBall[i][j].clear();
            fireBall[i][j] = tmpBall[i][j];
        }
    }
}

void divideBall()
{
    vector<Ball> tmpBall[MAX][MAX];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if ( fireBall[i][j].size() == 1){
                tmpBall[i][j] = fireBall[i][j];
            }
            else if ( fireBall[i][j].size() >= 2){
                int totalS=0;
                int totalM=0;
                bool even=false;
                bool odd=false;
                
                for(int k=0;k<fireBall[i][j].size();k++){
                    int dir=fireBall[i][j][k].d;
                    if(dir % 2 == 0)    even = true;
                    else    odd = true;
                    
                    totalS+=fireBall[i][j][k].s;
                    totalM+=fireBall[i][j][k].m;
                }
                
                int m = totalM/5;
                int s = totalS/fireBall[i][j].size();
                int dir = even && odd ? 1 : 0;
                 if ( m > 0)
                 {
                     for(int d=dir;d<8;d+=2){
                        tmpBall[i][j].push_back({m,s,d});
                    }
                 }
            }
            fireBall[i][j].clear();
            fireBall[i][j] = tmpBall[i][j];
        }
    }
    
}

int main(void)
{
    ios::sync_with_stdio(false);
    
    cin >> N >> M >> K;
    
    for(int i=0;i<M;i++){
        int x,y,m,s,d;
        cin >> x >> y >> m >> s >> d;
        fireBall[x][y].push_back({m,s,d});
    }
    for(int i=0;i<K;i++){
        moveBall();
        divideBall();
    }
    
    long long totalM =0;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<fireBall[i][j].size();k++)    totalM+=fireBall[i][j][k].m;
        }
    }
    
    cout << totalM;
    return 0;
}
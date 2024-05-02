#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;//2 <= N <= 10, 2 <= M <= 20
vector<vector<int> > board;
vector<vector<vector<bool> > > isVisited;
//최대 100초

int dy[]= {0,0,1,-1};
int dx[]= {1,-1,0,0};

typedef struct Bridge{
    int t;
    int y;
    int x;
    bool isUsed;

    Bridge(int t,int y, int x, bool isUsed): t(t),y(y),x(x),isUsed(isUsed){}
} Bridge;

struct cmp{
    bool operator()(Bridge& a, Bridge& b){
        return a.t > b.t;
    }
};

bool isCanBridge(int y, int x){
    if((y+1 < N && board[y+1][x] == 0) || (y-1 >= 0 && board[y-1][x] == 0) && ((x+1<N && board[y][x+1] == 0) || (x-1 >= 0 && board[y][x-1] == 0))){
        return false;
    } else {
        return true;
    }
}

int main(){
    cin >> N >> M;

    board.assign(N, vector<int>(N,0));
    isVisited.assign(N, vector<vector<bool> >(N*N, vector<bool>(2,0)));
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> board[i][j];
        }
    }

    priority_queue<Bridge, vector<Bridge>, cmp> pq;
    pq.push(Bridge(0,0,0,0));

    while(1){
        if(pq.top().y == N-1 && pq.top().x == N-1){
            cout << pq.top().t << endl;
            return 0;
        }
        int t = pq.top().t;
        int y = pq.top().y;
        int x = pq.top().x;
        bool isUsed = pq.top().isUsed;
        pq.pop();

        if(isVisited[y][x][isUsed]){
            continue;
        }
        
        isVisited[y][x][isUsed] = true;
        if(board[y][x] == 1){
            pq.push(Bridge(t+1,y,x,isUsed));
        }

        
        for(int i = 0 ; i < 4; i++){
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(nextY < 0 || nextY == N || nextX < 0 || nextX == N){
                continue;
            }
            if(board[nextY][nextX] == 0){
                if(isUsed == false && board[y][x] == 1 && isCanBridge(nextY,nextX)){
                    pq.push(Bridge(t + M - (t) % M,nextY,nextX,true));
                }
            }
            else if(board[nextY][nextX] == 1){
                pq.push(Bridge(t+1,nextY,nextX,isUsed));
            }
            else if(board[nextY][nextX] >= 2 && board[y][x] == 1){
                pq.push(Bridge(t + board[nextY][nextX] - (t)%board[nextY][nextX],nextY,nextX,isUsed));
            }
        }

    }
}
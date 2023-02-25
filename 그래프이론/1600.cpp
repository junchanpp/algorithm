#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

struct Info{
    int y;
    int x;
    int countK;
    int countVisit;
};
Info make_info(int y, int x, int countK, int countVisit){
    Info info = {y,x,countK,countVisit};
    return info;
}

bool mapInfo[200][200];
int N,M;
int K;
bool visited[200][200][31];

int dyList[]={0,0,1,-1};
int dxList[]={1,-1,0,0};
int horseDyList[]={1,2,1,2,-1,-2,-1,-2};
int horseDxList[]={2,1,-2,-1,2,1,-2,-1};

int main(){
    cin >> K;
    cin >> M >> N;

    for(int n = 0; n<N;n++){
        for(int m =0; m<M;m++){
            cin >> mapInfo[n][m];
        }
    }

    queue<Info> q;
    q.push(make_info(0,0,0,0));
    while(!q.empty()){
        Info nowInfo = q.front();
        q.pop();
        int y =nowInfo.y;
        int x =nowInfo.x;
        int countK =nowInfo.countK;
        int countVisit =nowInfo.countVisit;
        if(x==M-1 && y == N-1){
            cout << countVisit;
            return 0;
        }
        if(visited[y][x][countK] != 0 || mapInfo[y][x] == true)continue;
        visited[y][x][countK] = true;
        if(countK < K){
            for(int i = 0; i<7;i++){
                int dy = horseDyList[i];
                int dx = horseDxList[i];
                if(y+dy < 0 || x+dx < 0 || y+dy >= N || x+dx >= M || mapInfo[y+dy][x+dx] == true){
                    continue;
                }
                q.push(make_info(y+dy,x+dx,countK+1,countVisit+1));
            }
        }
        for(int i = 0; i<4;i++){
            int dy = dyList[i];
            int dx = dxList[i];
            if(y+dy < 0 || x+dx < 0 || y+dy >= N || x+dx >= M || mapInfo[y+dy][x+dx] == true){
                continue;
            }\
            q.push(make_info(y+dy,x+dx,countK,countVisit+1));
        }
    }
    cout << -1;
    return 0;

}
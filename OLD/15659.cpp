#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

int M, N, V;
vector<vector<vector<int> > > maps; // 1이면 못 가는 곳, 2면 볼케이노 위치
vector<vector<int> > h;
vector<vector<bool> > isVisited;
vector<vector<pair<int, int> > > volcanos(201);

int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
int dm[]={-1,1,0,0};
int dn[]={0,0,-1,1};


void makeMaps(int t){
    maps.push_back(vector<vector<int> >(M,vector<int>(N,0)));
    if(t != 0){
        for(int m = 0; m<M;m++){
            for(int n = 0; n<N;n++){
                maps[t][m][n] = maps[t-1][m][n];

            }
        }
        for(int m = 0; m < M; m++){
            for(int n = 0; n < N; n++){
                if(maps[t-1][m][n] != 1){
                    continue;
                }
                for(int k = 0; k < 4; k++){
                    int nextM = dm[k]+m;
                    int nextN = dn[k]+n;
                    if(nextM >= M || nextN >= N || nextM < 0 || nextN < 0){
                        continue;
                    }
                    maps[t][nextM][nextN] = 1;
                }
            }
        }
    } else {
        for(int i = 0 ; i < volcanos.size(); i++){
            for(int j = 0; j < volcanos[i].size(); j++){
                maps[0][volcanos[i][j].first][volcanos[i][j].second] = 2;
            }
        }
    }

    if(t > 200){
        return;
    }
    for(int i = 0; i < volcanos[t].size(); i++){
        maps[t][volcanos[t][i].first][volcanos[t][i].second] = 1;
    }
    
}


int main(){
    int X, Y;
    cin >> M >> N >> V;
    cin >> X >> Y;
    X--;
    Y--;

    h.assign(M, vector<int>(N,0));
    isVisited.assign(M, vector<bool>(N,0));

    for(int m = 0 ; m < M; m++){
        for(int n = 0; n < N; n++){
            cin >> h[m][n];
        }
    }
    for(int v = 0; v < V; v++){
        int x, y, t;
        cin >> x >> y >> t;
        volcanos[t].push_back(make_pair(x-1,y-1));
        
    }

    queue<pair<int,int> > q;
    int time = 0;
    int maxHeight = -1;
    int timeForMaxHeight = 0;
    q.push(make_pair(X,Y));
    makeMaps(0);
    while(!q.empty()){
        int sizeForSameTime = q.size();
        for(int temp = 0; temp < sizeForSameTime;temp++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(h[x][y] > maxHeight){
                maxHeight = h[x][y];
                timeForMaxHeight = time;
            }

            if(maps.size() == time+1){
                makeMaps(time+1);
            }

            for(int i = 0 ; i < 4; i++){
                int nextX = dx[i]+x;
                int nextY = dy[i]+y;
                if(nextX >= M || nextY >= N || nextX< 0 || nextY < 0){
                    continue;
                }
                if(maps[time+1][nextX][nextY]){
                    continue;
                }
                if(isVisited[nextX][nextY]){
                    continue;
                }
                isVisited[nextX][nextY] = true;
                q.push(make_pair(nextX,nextY));
            }
        }
        time++;
    }

    cout << maxHeight << " " << timeForMaxHeight;

}

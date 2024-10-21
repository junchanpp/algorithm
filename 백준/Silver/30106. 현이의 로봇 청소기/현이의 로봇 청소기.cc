#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int N, M, K;

vector<vector<int> > maps;
vector<vector<bool> > isClean;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void clean(int a, int b){
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));

    while(!q.empty()){
        int prevY = q.front().first;
        int prevX = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int y = prevY + dy[i];
            int x = prevX + dx[i];

            if(y >= N || x >= M || y < 0 || x < 0 || isClean[y][x] || abs(maps[y][x] - maps[prevY][prevX]) > K){
                continue;
            }
            q.push(make_pair(y, x));
            isClean[y][x] = 1;
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;
    maps.assign(N, vector<int>(M,0));
    isClean.assign(N, vector<bool>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> maps[i][j];
        }
    }

    int touchCount = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!isClean[i][j]){
                clean(i, j);
                touchCount++;
            }
        }
    }

    cout << touchCount;
}
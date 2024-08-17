#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

int N, M, K;
vector<vector<int> > map;

int directionY[] = {-1,-1,1,1};
int directionX[] = {-1,1,-1,1};

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int main(){
    cin >> N >> M;
    map.assign(N+1 , vector<int>(M+1,0));
    cin >> K;
    for(int i = 0; i < K; i++){
        int R, C, D;
        cin >> R >> C >> D;

        for(int j = 0; j <= D; j++){
            for(int k = 0; k < 4; k++){
                int nextY = R + j * directionY[k];
                int nextX = C + (D - j) * directionX[k];
                if(nextY > N || nextY < 1 || nextX > M || nextX < 1){
                    continue;
                }
                map[nextY][nextX] = 1;
            }
        }
    }

    priority_queue<pair<int, pair<int, int> > > pq;
    vector<vector<int> > visited;
    visited.assign(N+1, vector<int>(M+1, INT_MAX));

    pq.push(make_pair(0, make_pair(1,1)));
    visited[1][1] = 0;


    while(!pq.empty()){
        int count = pq.top().first * -1;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if(visited[y][x] < count){
            continue;
        }
        if(y == N && x == M){
            cout << "YES\n" << count;
            return 0;
        }

        for(int i = 0 ; i < 4; i++){
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            int nextCount = count + 1;
            if(nextY > N || nextY < 1 || nextX > M || nextX < 1){
                continue;
            }
            if(map[nextY][nextX] || visited[nextY][nextX] <= nextCount){
                continue;
            }
            visited[nextY][nextX] = nextCount;
            pq.push(make_pair(nextCount * -1, make_pair(nextY, nextX)));
        }

    }

    cout << "NO";
    
}
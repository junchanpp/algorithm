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
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

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

    queue<pair<int, int> > q;
    vector<vector<int> > visited;
    visited.assign(N+1, vector<int>(M+1, 0));

    q.push(make_pair(1,1));
    visited[1][1] = 1;
    int count = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if(y == N && x == M){
                cout << "YES\n" << count;
                return 0;
            }

            for(int i = 0 ; i < 4; i++){
                int nextY = y + dy[i];
                int nextX = x + dx[i];
                if(nextY > N || nextY < 1 || nextX > M || nextX < 1){
                    continue;
                }
                if(map[nextY][nextX] || visited[nextY][nextX]){
                    continue;
                }
                visited[nextY][nextX] = 1;
                q.push(make_pair(nextY, nextX));
            }
        }
        count++;
    }

    cout << "NO";
    
}
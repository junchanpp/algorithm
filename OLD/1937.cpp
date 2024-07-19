#include<iostream>
#include<vector>

using namespace std;

int N;
vector<vector<int> > inputs;
vector<vector<int> > visited;

int solve(int startY, int startX);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    inputs.assign(N, vector<int>(N,0));
    visited.assign(N, vector<int>(N,0));

    for(int i = 0 ; i < N;i++){
        for(int j = 0; j< N; j++){
            cin >> inputs[i][j];
        }
    }

    int max = 0;

    for(int i = 0 ; i < N;i++){
        for(int j = 0; j< N; j++){
            if(visited[i][j] == 0){
                int result = solve(i,j);
                if(max < result){
                    max = result;
                }
            }
        }
    }

    cout << max;


}
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};


int solve(int startY, int startX){
    if(visited[startY][startX] != 0){
        return visited[startY][startX];
    }
    int max = 1;
    for(int i = 0 ; i < 4;i++){
        int nextY = startY + dy[i];
        int nextX = startX + dx[i];
        if(nextY >= N || nextY < 0 || nextX >= N || nextX < 0){
            continue;
        }
        if(inputs[nextY][nextX] <= inputs[startY][startX]){
            continue;
        }
        int result = 1 + solve(nextY,nextX);
        if(max < result){
            max = result;
        }
    }
    return visited[startY][startX] = max;
}
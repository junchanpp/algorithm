#include <iostream>
#include <algorithm>

using namespace std;

int M,N;//M이 세로, N이 가로
int node[501][501];
int memo[501][501];

int dyList[] = {0,0,-1,1};
int dxList[] = {-1,1,0,0};

bool isOverRange(int y, int x){
    return y < 0 || x < 0 || y > M-1 || x > N-1;
}

int solve(int y, int x){
    if(y==M-1 && x==N-1)return 1;
    if(memo[y][x] != -1)return memo[y][x];
    int sum = 0;
    for(int i = 0;i < 4; i++){
        int newY = y+dyList[i];
        int newX = x+dxList[i];
        if(isOverRange(newY,newX))continue;
        if(node[y][x] > node[newY][newX])sum += solve(newY,newX);
    }
    memo[y][x] = sum;
    return sum;
}
int main(){
    cin >> M >> N;
    fill(&memo[0][0], &memo[0][0]+501*501,-1);
    for(int i = 0; i<M;i++){
        for(int j = 0; j<N;j++){
            cin >> node[i][j];
        }
    }

    cout << solve(0,0);

}
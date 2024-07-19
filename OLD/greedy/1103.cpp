#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
int N,M;
int board[50][50];
bool visited[50][50];
int memo[50][50];

int dyList[] = {0,0,-1,1};
int dxList[] = {-1,1,0,0};


int solve(int y,int x){//무한대면 return true;
    if(memo[y][x] !=0)return memo[y][x];
    int longNum = 1;
    for(int i = 0; i < 4;i++){
        int newY = y+ dyList[i]*board[y][x];
        int newX = x+ dxList[i]*board[y][x];
        if(newY > N-1 || newX > M-1 || newY <0 || newX < 0 || board[newY][newX]==0)continue;
        if(visited[newY][newX])return -1;
        visited[newY][newX] = true;
        int result = solve(newY,newX);
        visited[newY][newX] = false;
        if(result == -1){
            return -1;
        }
        if(result+1 > longNum)longNum = result+1;
    }
    memo[y][x] = longNum;
    return longNum;
}

int main(){
    cin >> N >> M;
    for(int i =0 ; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M;j++){
            if(s[j]=='H')board[i][j] = 0;
            else board[i][j] = s[j]-'0';
        }
    }
    queue<pair<int,pair<int,int> > > q;
    fill(&visited[0][0], &visited[0][0]+50*50,0);
    fill(&memo[0][0], &memo[0][0]+50*50,0);
    int counting = solve(0,0);
    if(counting == -1)cout << -1<< endl;
    else cout << counting << endl;
    
}
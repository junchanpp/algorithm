#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve();
int dp(int y, int x, int index);
int N, M, K;
vector<vector<char> > arr;

string word;
int directionYList[] = {0,0,-1,1};
int directionXList[] = {-1,1,0,0};
vector<vector<vector<int> > > memo;


int main(){
    cin >> N >> M >> K;

    arr.assign(N, vector<char>(M));
    

    for(int i = 0 ; i  < N; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < M; j++){
            arr[i][j] = s[j];
        }
    }

    cin >> word;
    memo.assign(N, vector<vector<int> >(M, vector<int>(word.size(),-1)));//memo[i][j][k] : (i,j)에서 k번째 문자열로 선택됐을 때 나머지 문자열을 완성시킬 수 있는 경우의 수

    cout << solve();

    return 0;
}



int solve(){
    int sum = 0;
    for(int i = 0 ; i  < N; i++){
        for(int j = 0 ; j < M; j++){
            if(arr[i][j] == word[0]){
                sum += dp(i,j,0);
            }
        }
    }

    return sum;
}

int dp(int y, int x, int index){
    if(memo[y][x][index]!= -1){
        return memo[y][x][index];
    }
    if(index == word.size()-1){
        return 1;
    }
    int sum = 0;
    int nextIndex = index + 1;

    for(int i = 0 ; i < 4; i++){
        for(int k = 1; k <= K; k++){
            int dy = directionYList[i] * k;
            int dx = directionXList[i] * k;
            int nextY = y+dy;
            int nextX = x+dx;

            if(nextY >= N || nextX >= M || nextY < 0 || nextX < 0){
                continue;
            }
            if(arr[nextY][nextX] == word[nextIndex]){
                sum += dp(nextY,nextX,nextIndex);
            }
        }
    }

    return memo[y][x][index] = sum;
    
}
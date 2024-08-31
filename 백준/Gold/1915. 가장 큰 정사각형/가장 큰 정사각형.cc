#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;

vector<vector<int> > board;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    board.assign(N, vector<int>(M,0));
    int maxSize = 0;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            board[i][j] = s[j] - '0';
            if(board[i][j]){
                maxSize = 1;
            }
        }
    }


    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            if(!board[i][j]){
                continue;
            }
            board[i][j] = min(board[i-1][j], min(board[i][j-1], board[i-1][j-1])) + 1;
            if(maxSize < board[i][j]){
                maxSize = board[i][j];
            }
        }
    }

    cout << maxSize * maxSize;

}
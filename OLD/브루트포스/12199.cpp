#include <iostream>

using namespace std;

int maxNum = -1;
int N;
void solve(int count, int board[][20]){
    if(count == 0){
        for(int i = 0 ; i< N; i++){
            for(int j = 0; j< N; j++){
                if(board[i][j] > maxNum){
                    maxNum = board[i][j];
                }
            }
        }
        return;
    }
    int newBoard[20][20]={0,};

    for(int j = 0; j < N; j++){
        int minValue = 0;
        for(int i = 0 ; i < N; i++){
            int newI = i;
            while(newI >= minValue && newBoard[newI][j] == 0)newI--;
            if(newI < minValue) newBoard[minValue][j] = board[i][j];
            else if(newI != i && board[i][j] == newBoard[newI][j]) {newBoard[newI][j] = board[i][j]*2;minValue = newI+1;}
            else if(newI != i && board[i][j] != newBoard[newI][j]) newBoard[newI+1][j] = board[i][j];
            else newBoard[newI+1][j] = board[i][j];
        }
    }
    solve(count-1, newBoard);
    
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j< N; j++){
            newBoard[i][j] = 0;
        }
    }

    
    for(int j = 0 ; j < N; j++){
        int maxValue = N-1;
        for(int i = N-1; i >= 0; i--){
            int newI = i;
            while(newI <= maxValue && newBoard[newI][j] == 0)newI++;
            if(newI > maxValue) newBoard[maxValue][j] = board[i][j];
            else if(newI != i && board[i][j] == newBoard[newI][j]) {newBoard[newI][j] = board[i][j]*2;maxValue = newI-1;}
            else if(newI != i && board[i][j] != newBoard[newI][j]) newBoard[newI-1][j] = board[i][j];
            else newBoard[newI+1][j] = board[i][j];
        }
    }
    solve(count-1, newBoard);


    for(int i = 0; i < N; i++){
        for(int j = 0 ; j< N; j++){
            newBoard[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        int minValue = 0;
        for(int j = 0 ; j < N; j++){
            int newJ = j;
            while(newJ >= minValue && newBoard[i][newJ] == 0)newJ--;
            if(newJ <minValue) newBoard[i][minValue] = board[i][j];
            else if(newJ != j && board[i][j] == newBoard[i][newJ]) {newBoard[i][newJ] = board[i][j]*2;minValue = newJ+1;}
            else if(newJ != j && board[i][j] != newBoard[i][newJ]) newBoard[i][newJ+1] = board[i][j];
            else newBoard[i][newJ+1] = board[i][j];
        }
    }
    solve(count-1, newBoard);
    
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j< N; j++){
            newBoard[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++){
        int maxValue = N-1;
        for(int j = N-1; j >= 0; j--){
            int newJ = j;
            while(newJ <= maxValue && newBoard[i][newJ] == 0)newJ++;
            if(newJ > maxValue) newBoard[i][maxValue] = board[i][j];
            else if(newJ != j && board[i][j] == newBoard[i][newJ]) {newBoard[i][newJ] = board[i][j]*2;maxValue=newJ-1;}
            else if(newJ != j && board[i][j] != newBoard[i][newJ]) newBoard[i][newJ-1] = board[i][j];
            else newBoard[i][newJ-1] = board[i][j];
        }
    }
    solve(count-1, newBoard);
}

int main(){
    cin >> N;
    int board[20][20]={0,};

    for(int i = 0 ; i< N; i++){
        for(int j = 0; j< N; j++){
            cin >> board[i][j];
        }
    }

    solve(5, board);

    cout << maxNum << endl;
}
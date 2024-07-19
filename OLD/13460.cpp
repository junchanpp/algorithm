#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct cmp{
    bool operator()(pair<int, vector<vector<char> > >& a, pair<int, vector<vector<char> > >& b){
        return a.first > b.first;
    }
};

bool isVisited[10][10][10][10];

int N, M;//N 세로, M 가로
vector<vector<char> > board;
priority_queue<pair<int, vector<vector<char> > >, vector<pair<int, vector<vector<char> > > > , cmp > pq;

vector<vector<char> > moveBoard(char c, vector<vector<char> >& board, int i, int j){
    switch(c){
        case 'U':
            while(i-1 >= 0 && board[i-1][j] != '#' && board[i-1][j] != 'R' &&board[i-1][j] != 'B'){
                if(board[i-1][j] == 'O'){
                    board[i][j] = '.';
                    return board;
                }
                board[i-1][j] = board[i][j];
                board[i][j] = '.';
                i--;
            }
            break;
        case 'D':
            while(i+1 < N && board[i+1][j] != '#' && board[i+1][j] != 'R' &&board[i+1][j] != 'B'){
                if(board[i+1][j] == 'O'){
                    board[i][j] = '.';
                    return board;
                }
                board[i+1][j] = board[i][j];
                board[i][j] = '.';
                i++;
            }
            break;
        case 'R':
            while(j+1 < M && board[i][j+1] != '#' && board[i][j+1] != 'R' &&board[i][j+1] != 'B'){
                if(board[i][j+1] == 'O'){
                    board[i][j] = '.';
                    return board;
                }
                board[i][j+1] = board[i][j];
                board[i][j] = '.';
                j++;
            }
            break;
        case 'L':
            while(j-1 >= 0 && board[i][j-1] != '#' && board[i][j-1] != 'R' &&board[i][j-1] != 'B'){
                if(board[i][j-1] == 'O'){
                    board[i][j] = '.';
                    return board;
                }
                board[i][j-1] = board[i][j];
                board[i][j] = '.';
                j--;
            }
            break;
    }

    return board;
}

bool isNotFoundBlue(vector<vector<char> >& board){
    bool isFound = false;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j< M; j++){
            if(board[i][j] =='B'){
                return false;
            }
        }
    }
    return true;
}


bool isNotFoundRed(vector<vector<char> >& board){
    bool isFound = false;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j< M; j++){
            if(board[i][j] =='R'){
                return false;
            }
        }
    }
    return true;
}

int solve(){
    pq.push(make_pair(0, vector<vector<char> >(board)));

    while(!pq.empty()){
        pair<int, vector<vector<char> > > nowInfo = pq.top();
        
        pq.pop();
        
        if(nowInfo.first == 10){
            break;
        }

        int count = nowInfo.first + 1;
        vector<vector<char> > nowBoard = nowInfo.second;

        //1. 위로 기울이기
        vector<vector<char> > boardForMoveUp(nowBoard);
        for(int i = 0 ; i < N;i++){
            for(int j = 0 ; j<M;j++){
                if(boardForMoveUp[i][j] == 'B' || boardForMoveUp[i][j] == 'R'){
                    boardForMoveUp = moveBoard('U', boardForMoveUp, i, j);
                }
            }
        }
        if(isNotFoundBlue(boardForMoveUp)){
            
            // do not
        } else if(isNotFoundRed(boardForMoveUp)) {
            return count;
        } else {
            pq.push(make_pair(count, vector<vector<char> >(boardForMoveUp)));
        }

        //2. 왼쪽으로 기울이기
        vector<vector<char> > boardForMoveLeft(nowBoard);
        for(int i = 0 ; i < N;i++){
            for(int j = 0 ; j<M;j++){
                if(boardForMoveLeft[i][j] == 'B' || boardForMoveLeft[i][j] == 'R'){
                    boardForMoveLeft = moveBoard('L', boardForMoveLeft, i, j);
                }
            }
        }
        if(isNotFoundBlue(boardForMoveLeft)){
            
            // do not
        } else if(isNotFoundRed(boardForMoveLeft)) {
            return count;
        } else {
            pq.push(make_pair(count, vector<vector<char> >(boardForMoveLeft)));
        }


        //3. 아래로 기울이기
        vector<vector<char> > boardForMoveDown(nowBoard);
        
        for(int i = N-1 ; i >= 0;i--){
            for(int j = 0 ; j<M;j++){
                if(boardForMoveDown[i][j] == 'B' || boardForMoveDown[i][j] == 'R'){
                    boardForMoveDown = moveBoard('D', boardForMoveDown, i, j);

                }
            }
        }
        
        if(isNotFoundBlue(boardForMoveDown)){
            
            // do not
        } else if(isNotFoundRed(boardForMoveDown)) {
            return count;
        } else {
            pq.push(make_pair(count, vector<vector<char> >(boardForMoveDown)));
        }

        //4. 오른쪽으로 기울이기
        vector<vector<char> > boardForMoveRight(nowBoard);
        for(int i = 0 ; i < N;i++){
            for(int j = M -1 ; j>=0;j--){
                if(boardForMoveRight[i][j] == 'B' || boardForMoveRight[i][j] == 'R'){
                    boardForMoveRight = moveBoard('R', boardForMoveRight, i, j);
                }
            }
        }
        if(isNotFoundBlue(boardForMoveRight)){
            
            // do not
        } else if(isNotFoundRed(boardForMoveRight)) {
            return count;
        } else {
            pq.push(make_pair(count, vector<vector<char> >(boardForMoveRight)));
        }

        
    }

    return -1;
}

int main(){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    board.assign(N, vector<char>(M));
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < M; j++){
            board[i][j]= s[j];
        }
    }
    
    
    cout <<solve();


    return 0;

}
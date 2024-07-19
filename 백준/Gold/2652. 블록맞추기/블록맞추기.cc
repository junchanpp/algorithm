#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define START_BLOCK_NUM 2

using namespace std;

vector<vector<int> > board;
int N;
int u, v, w, x, y;
int blockNum = START_BLOCK_NUM;

vector<pair<int, int> > answer;

void insertBlockNumToBoard(int a, int b, int n){
    queue<pair<int, int> > q;
    q.push(make_pair(a,b));

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        int a = p.first;
        int b = p.second;
        if(a < 0 || a == N || b < 0 || b == N){
            continue;
        }
        if(board[a][b] != 1){
            continue;
        }
        board[a][b] = n;
        q.push(make_pair(a+1,b));
        q.push(make_pair(a-1,b));
        q.push(make_pair(a,b+1));
        q.push(make_pair(a,b-1));
    }
}

char getDirection(int minX, int minY,int maxX, int maxY, int n){

    
    int lastMeet = minY;
    for(int i = minY+1 ; i <= maxY;i++){
        if(board[maxX][i] != 0){
            if(lastMeet != i-1){
                return 'U';
            }else {
                lastMeet = i;
            }
        }
    }
    lastMeet = minY;
    
    for(int i = minY+1 ; i <= maxY;i++){
        if(board[minX][i] != 0){
            if(lastMeet != i-1){
                return 'D';
            }else {
                lastMeet = i;
            }
        }
    }
    lastMeet = minX;
    
    for(int i = minX+1; i <= maxX;i++){
        if(board[i][minY] != 0){
            if(lastMeet != i-1){
                return 'R';
            }else {
                lastMeet = i;
            }
        }
    }

    
    return 'L';


}

int getMaxX(int a, int b, int nowNum){
    int maxX = a;
    for(int i = a+1; i < N; i++){
        if(board[i][b] == nowNum){
            maxX = i;
        }
    }

    return maxX;
}
int getMaxY(int a, int b, int nowNum){
    int maxY = b;
    for(int i = b+1; i < N; i++){
        if(board[a][i] == nowNum){
            maxY = i;
        }
    }

    return maxY;
}

bool isCanInsert(int a, int b){
    int nowNum = blockNum;
    blockNum++;

    
    insertBlockNumToBoard(a, b, nowNum);
    
    
    int minX = a;
    int minY = b;
    int maxX = getMaxX(a,b, nowNum);
    int maxY = getMaxY(a,b, nowNum);

    char direction = getDirection(minX,minY,maxX,maxY,nowNum);

    switch(direction){

            int emptyStartY;
            int emptyEndY;

            int emptyStartX;
            int emptyEndX;
            int expandX;
            int expandY;

        case 'U':
            
            if(u != maxY -minY +1){
                return false;
            }
            emptyStartY = minY + w;
            emptyEndY = emptyStartY+y - 1;

            emptyStartX = maxX -x + 1;
            emptyEndX = maxX;
            expandX = maxX+ v;

            for(int i = minY; i <= maxY; i++){
                for(int j = minX; j <= maxX;j++){
                    if(emptyStartY <= i && i <= emptyEndY && emptyStartX <= j && j <= emptyEndX){
                        if(board[j][i] != 0){
                            return false;
                        }
                    }else {
                        if(board[j][i] != nowNum){
                            return false;
                        }
                    }
                }
            }
            if(expandX >= N){
                return false;
            }
            for(int j = emptyEndX+1; j <= expandX; j++){
                for(int i = minY; i <= maxY; i++){
                    if(board[j][j] != 0){
                        return false;
                    }
                }
            }
            break;
        case 'D':
            if(u != maxY -minY +1){
                return false;
            }
            emptyEndY = maxY - w;
            emptyStartY = emptyEndY - y + 1;

            emptyStartX = minX;
            emptyEndX = minX + x -1;
            expandX = minX - v;

            for(int i = minY; i <= maxY; i++){
                for(int j = minX; j <= maxX;j++){
                    if(emptyStartY <= i && i <= emptyEndY && emptyStartX <= j && j <= emptyEndX){
                        if(board[j][i] != 0){
                            return false;
                        }
                    }else {
                        if(board[j][i] != nowNum){
                            return false;
                        }
                    }
                }
            }

            if(expandX < 0){
                return false;
            }
            for(int j = expandX; j <= emptyStartX-1; j++){
                for(int i = minY; i <= maxY; i++){
                    if(board[j][j] != 0){
                        return false;
                    }
                }
            }
            break;  
        case 'R':
            if(u != maxX-minX + 1){
                return false;
            }
            emptyStartX = minX + w;
            emptyEndX = emptyStartX+y - 1;

            emptyStartY = minY;
            emptyEndY = minY + x -1;
            expandY = minY - v;
            
            for(int i = minX; i <= maxX; i++){
                for(int j = minY; j <= maxY;j++){
                    if(emptyStartX <= i && i <= emptyEndX && emptyStartY <= j && j <= emptyEndY){
                        if(board[i][j] != 0){
                            return false;
                        }
                    }else {
                        if(board[i][j] != nowNum){
                            return false;
                        }
                    }
                }
            }
            if(expandY < 0){
                return false;
            }


            for(int j = emptyEndY+1; j <= expandY; j++){
                for(int i = minX; i <= maxX; i++){
                    if(board[j][j] != 0){
                        return false;
                        }
                }
            }
            break;
        case 'L':
            if(u != maxX-minX + 1){
                return false;
            }
            emptyEndX = maxX - w;
            emptyStartX = emptyEndX - y + 1;

            emptyStartY = maxY -x + 1;
            emptyEndY = maxY;
            expandY = maxY+ v;

            for(int i = minY; i <= maxY; i++){
                for(int j = minX; j <= maxX;j++){
                    if(emptyStartY <= i && i <= emptyEndY && emptyStartX <= j && j <= emptyEndX){
                        if(board[j][i] != 0){
                            return false;
                        }
                    }else {
                        if(board[j][i] != nowNum){
                            return false;
                        }
                    }
                }
                
                
            }
            if(expandY >= N){
                return false;
            }
            for(int j = expandY; j <= emptyStartY-1; j++){
                for(int i = minX; i <= maxX; i++){
                    if(board[j][j] != 0){
                        return false;
                    }
                }
            }
            break;
    }

    return true;    
}

int main(){

    cin >> N;

    board.assign(N+1, vector<int>(N+1));

    cin >> u >> v >> w >> x >> y;

    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j]==1){
                if(isCanInsert(i,j)){
                    answer.push_back(make_pair(i+1,j+1));
                }
            }
        }
    }

    cout << answer.size() << endl;

    for(int i = 0; i < answer.size();i++){
        cout << answer[i].first << " "<< answer[i].second << endl;
    }

}
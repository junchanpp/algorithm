#include <iostream>
#include <queue>

using namespace std;
int N;

typedef struct Wood{
    int y;
    int x;
    bool isWidth;
    int count;
}Wood;

Wood make_wood(int y , int x, int isWidth, int count){
    Wood wood={y,x,isWidth, count};
    return wood;
}
bool visited[50][50][2];//중심점 좌표와 가로,세로 여부에 따라 방문 여부 체크
int board[50][50];

Wood findWood(int type){
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j< N; j++){
            if(board[i][j] == type){
                if(board[i][j+1] == type){
                    return make_wood(i,j+1,true,0);
                }else {
                    return make_wood(i+1,j,false,0);
                }
            }
        }
    }
}
bool isEqual(Wood& w1, Wood& w2){
    return w1.y == w2.y && w1.x == w2.x && w1.isWidth == w2.isWidth;
}
bool isCanUp(Wood w){
    if(w.isWidth){
        if(w.y+1 > N-1)return false;
        if(board[w.y+1][w.x-1] != 1 && board[w.y+1][w.x] != 1 && board[w.y+1][w.x+1] != 1)return true;
    }else {
        if(w.y+2 > N-1)return false;
        if(board[w.y+2][w.x] != 1)return true;
    }
    return false;
}
bool isCanDown(Wood w){
    if(w.isWidth){
        if(w.y-1 < 0)return false;
        if(board[w.y-1][w.x-1] != 1 && board[w.y-1][w.x] != 1 && board[w.y-1][w.x+1] != 1)return true;
    }else {
        if(w.y-2 < 0)return false;
        if(board[w.y-2][w.x] != 1)return true;
    }
    return false;
}
bool isCanLeft(Wood w){
    if(w.isWidth){
        if(w.x-2 < 0)return false;
        if(board[w.y][w.x-2] != 1)return true;
    }else {
        if(w.x-1 < 0)return false;
        if(board[w.y-1][w.x-1] != 1 && board[w.y][w.x-1] != 1 && board[w.y+1][w.x-1] != 1)return true;
    }
    return false;
}
bool isCanRight(Wood w){
    if(w.isWidth){
        if(w.x+2 > N-1)return false;
        if(board[w.y][w.x+2] != 1)return true;
    }else {
        if(w.x+1 > N-1)return false;
        if(board[w.y-1][w.x+1] != 1 && board[w.y][w.x+1] != 1 && board[w.y+1][w.x+1] != 1)return true;
    }
    return false;
}
bool isCanTurn(Wood w){
    for(int i = w.y -1; i <= w.y+1; i++){
        for(int j = w.x - 1; j <=w.x+1; j++){
            if(i > N-1 || i < 0 || j > N-1 || j < 0)return false;
            if(board[i][j] == 1)return false;
        }
    }
    return true;
}
Wood up(Wood w){
    return make_wood(w.y+1,w.x,w.isWidth,w.count+1);
}
Wood down(Wood w){
    return make_wood(w.y-1,w.x,w.isWidth,w.count+1);
}
Wood left(Wood w){
    return make_wood(w.y,w.x-1,w.isWidth,w.count+1);
}
Wood right(Wood w){
    return make_wood(w.y,w.x+1,w.isWidth,w.count+1);
}
Wood turn(Wood w){
    return make_wood(w.y,w.x,!(w.isWidth),w.count+1);
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N;i++){
        string s;
        cin >> s;
        for(int j = 0 ; j < N;j++){
            board[i][j] = s[j] == 'B' ? 2 : s[j] == 'E' ? 3 : s[j] == '1' ? 1 : 0;
        }
    }

    Wood w = findWood(2);
    Wood dest = findWood(3);

    queue<Wood> q;
    q.push(w);

    while(!q.empty()){
        Wood wood = q.front();
        q.pop();
        if(visited[wood.y][wood.x][wood.isWidth])continue;
        visited[wood.y][wood.x][wood.isWidth] = true;
        if(isEqual(wood,dest)){
            cout << wood.count;return 0;
        }

        if(isCanUp(wood)){
            q.push(up(wood));
        }
        if(isCanDown(wood)){
            q.push(down(wood));
        }
        if(isCanLeft(wood)){
            q.push(left(wood));
        }
        if(isCanRight(wood)){
            q.push(right(wood));
        }
        if(isCanTurn(wood)){
            q.push(turn(wood));
        }
    }
    cout<< 0;
    return 0;
}
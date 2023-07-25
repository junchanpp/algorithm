#include <iostream>
#include <string>
#include <queue>
#include <math.h>

using namespace std;
int N,M;
bool board[15][15];
int dyList[] = {0,0,-1,1};
int dxList[] = {-1,1,0,0};

int maxSize;

int calc2(){
    int calcSize = 0;
    for(int i = 0; i<N;i++){
        for(int j = 0; j<M;j++){
            int size = 0;
            for(;size<=maxSize;size++){
                bool isAllOk = true;
                for(int a = 0;a<4;a++){
                    int newY = i+dyList[a]*size;
                    int newX = j+dxList[a]*size;
                    if(newY > N-1 || newY < 0 || newX > M-1 || newX < 0 || !board[newY][newX])isAllOk = false;
                }
                if(!isAllOk)break;
            }
            if(calcSize < size-1)calcSize = size-1;
        }
    }
    return calcSize;
}
int calc(){
    int calcSize = 0;
    int boardBackUp[15][15];
    copy(&board[0][0], &board[0][0]+15*15,&boardBackUp[0][0]);
    for(int i = 0; i<N;i++){
        for(int j = 0; j<M;j++){
            int size = 0;
            int sumSize = 0;
            for(;size<=maxSize;size++){
                bool isAllOk = true;
                for(int a = 0;a<4;a++){
                    int newY = i+dyList[a]*size;
                    int newX = j+dxList[a]*size;
                    if(newY > N-1 || newY < 0 || newX > M-1 || newX < 0 || !board[newY][newX]){
                        isAllOk= false;
                    }else {
                        board[newY][newX] = 0;
                        if(size ==0)break;
                    }
                }
                if(!isAllOk)break;
                else{
                    int newSize = calc2();
                    if(sumSize < (1+newSize*4)*(1+size*4)){
                        sumSize = (1+newSize*4)*(1+size*4);
                    }
                }
            }
            if(calcSize < sumSize)calcSize = sumSize;
            copy(&boardBackUp[0][0], &boardBackUp[0][0]+15*15,&board[0][0]);
        }
    }
    return calcSize;
}

int main(){
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        string s;
        cin >>s;
        for(int j = 0; j<M;j++){
            board[i][j] = (s[j] =='#' ? 1 : 0);
        }
    }
    maxSize = (min(N,M)-1)/2;
    cout << calc();
}
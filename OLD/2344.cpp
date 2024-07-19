#include <iostream>
#include <vector>

using namespace std;

int N, M;

// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};
// int transDx[4] = {0,0,-1,1};
// int transDy[4] = {-1,1,0,0};

int leftArr[1000];
int downArr[1000];
int rightArr[1000];
int upArr[1000];
int arr[1000][1000];

int solve(int x, int y, int dx, int dy){
    while(1){
        if(arr[y][x]==1){//거울 있음
            int tempDx = dx;
            dx = dy*(-1);
            dy = tempDx*(-1);
        }
        y+= dy;
        x+= dx;

        if(y < 0){
            return upArr[x];
        }
        if(x < 0){
            return leftArr[y];
        }
        if(y >= N){
            return downArr[x];
        }
        if(x >= M){
            return rightArr[y];
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < M; j++){
            cin >> arr[i][j];
        }
    }

    //번호 매기기
    for(int i = 0 ; i < N;i++){
        leftArr[i] = i+1;
    }
    for(int i = 0 ; i < M;i++){
        downArr[i] = N+i+1;
    }
    for(int i = 0 ; i < N;i++){
        rightArr[i] = N+M+(N - i);
    }
    for(int i = 0 ; i < M;i++){
        upArr[i] = N+M+N+(M-i);
    }

    //순서대로 출력
    for(int i = 0 ; i < N;i++){
        cout << solve(0,i,1,0) << " ";
    }
    for(int i = 0 ; i < M;i++){
        cout << solve(i,N-1,0,-1) << " ";
    }
    for(int i = 0 ; i < N;i++){
        cout << solve(M-1,N-(i+1),-1,0) << " ";
    }
    for(int i = 0 ; i < M;i++){
        cout << solve(M-(i+1),0,0,1) << " ";
    }
}
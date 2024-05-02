#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>

using namespace std;

int N, M, L, T, K;

vector<vector<char> > board[362];//각 t/10마다 선생들 위치 포함 지도 미리 그려두기.
int dy[9] = {0,0,0,-1,-1,-1,1,1,1};
int dx[9] = {-1,1,0,-1,1,0,-1,1,0};


void initBoard(){
    for(int i = 0; i <= T/10 + 1; i++){
        board[i].assign(N+2, vector<char>(M+2));
    }

    for(int i = 1 ; i <= N; i++){
        char tmp[M+1];
        scanf("%s", tmp);
        for(int j = 1; j<= M;j++){
            for(int k = 0; k <= T/10;k++){
                board[k][i][j] = tmp[j-1];
            }
        }
    }
}

void initTeachers(){

    for(int i = 0; i < L ;i++){//기본 입력 받기
        int p;
        scanf("%d", &p);

        vector<pair<int, int> > teacher;
        for(int j = 0 ; j < p ; j++){
            int y, x;
            scanf("%d %d", &y, &x);
            teacher.push_back(make_pair(y,x));
        }
        for(int i = 0 ; i <= T/10+1; i++){
            int p = teacher.size();

            for(int a = 0 ; a < 9; a++){
                if(teacher[i%p].first+dy[a] < 1 || teacher[i%p].first+dy[a] > N || teacher[i%p].second+dx[a] < 1 || teacher[i%p].second+dx[a] > M){
                    continue;
                }
                if(teacher[i%p].first+dy[a] == 1 && teacher[i%p].second+dx[a] == 1){
                    continue;
                }
                if(teacher[i%p].first+dy[a] == N && teacher[i%p].second+dx[a] == M){
                    continue;
                }
                board[i][teacher[i%p].first+dy[a]][teacher[i%p].second+dx[a]] = 'T';
            }
        }
    }
}


bool isCanGo[1001][1001][2][2];// y, x, (t/10)%2, isAte;
bool solve(){
    bool isAte = 0;
    isCanGo[1][1][1][0] = 1;

    int time = 0;// time = t/10
    for(; time <= (T/10) + (T % 10 >= 5 ? 0 : -1); time++){
        int isCanGoThirdIndex = time % 2;
        for(int i = 1 ; i <= N;i++){
            for(int j = 1 ; j <= M; j++){
                bool isExist = false;
                for(int k = 0 ; k < 9;k++){
                    if(i+dy[k] < 1 || j+dx[k] < 1 || i+dy[k] > N || j+dx[k] > M){
                        continue;
                    }
                    if(board[max(0,time-1)][i][j] == '#' || board[max(0,time-1)][i][j] == 'T'){
                        continue;
                    }
                    if(board[time][i][j] == '#' || board[time][i][j] == 'T'){
                        continue;
                    }
                    if(isCanGo[i+dy[k]][j+dx[k]][!isCanGoThirdIndex][isAte]){// 바로 이전에 근처로 파댕이가 갈 수 있었으면 지금도 갈 수 있음.
                        isExist = true;
                        break;
                    }
                }
                isCanGo[i][j][isCanGoThirdIndex][isAte] = isExist;
            }
        }
        if(isCanGo[isAte ? 1 : N][isAte ? 1 : M][isCanGoThirdIndex][isAte]){
            if(isAte){
                return true;
            }
            
            time += ((K-1)/10);
            isCanGo[N][M][(time)%2][1] = true;
            isAte = true;
        }
    }

    return false;
    
}

int main(){
    scanf("%d %d %d %d %d", &N, &M, &L, &T, &K);
    
    if(200 < max(N,M)){
        printf("SAD");
        return 0;
    }


    initBoard();
    initTeachers();
    
    printf(solve() ? "YUMMY" : "SAD");
}
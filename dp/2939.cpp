#include <iostream>

using namespace std;

int R,C;
int D;
int cost[20001][201];
int dest[200001][2];


int main(){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1 ; j <= C; j++){
            scanf("%d", &cost[i][j]);
        }
    }
    cin >> D;
    for(int i = 0 ; i < D; i++){
        scanf("%d %d", &dest[i][0], &dest[i][1]);
    }

    for(int i = 0 ; i < 2401; i++){
        for(int j = 0 ; j < 2401; j++){
            memo[i][j] = -1;
        }
    }

    for(int i = 0 ; i < D; i++){
        int cost += 200000
    }
}
#include <iostream>
#include <vector>

using namespace std;

int N;

bool edge[257][257]= {0,};

int memo[257][257];

int solve(int a, int b){
    cout << a << " " << b<< endl;
    if(a == b && a == N){
        return 1;
    }
    if(memo[a][b] != -1){
        return memo[a][b];
    }
    if(a > b){
        int maxSize = 0;
        for(int i = b+1 ; i <= N; i++){
            if(edge[a][i] && (a!=i || a == N)){
                int size = solve(a,i);
                if(size > maxSize)maxSize = size;
            }
        }
        return memo[a][b] = maxSize == 0 ? 0 : maxSize + 1;
    }else {
        int maxSize = 0;
        for(int i = a+1 ; i <= N; i++){
            if(edge[i][b] && (b!=i || b == N)){
                int size = solve(i,b);
                if(size > maxSize)maxSize = size;
            }
        }
        return memo[a][b] = maxSize == 0 ? 0 : maxSize + 1;

    }
}

int main(){
    for(int i = 0; i < 257; i++){
        for(int j = 0 ; j < 257; j++){
            memo[i][j]= -1;
        }
    }
    scanf("%d", &N);

    while(1){
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        if(temp1 == temp2 && temp1 == 0)break;
        edge[temp1][temp2] = 1;
        edge[temp2][temp1] = 1;
    }

    int ans = solve(1,1);

    cout << ans << endl;
}


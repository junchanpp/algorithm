#include <iostream>
using namespace std;

int dp[201][201];

int main(){
    int N,K;
    cin >> N >> K;
    for(int i = 0; i<=N;i++){
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for(int i = 1; i<=K;i++){
        dp[0][i] = 1;
    }

    for(int i = 0; i < K; i++){
        for(int j = 0; j<N;j++){
            dp[j][i] = 
        }
    }
}
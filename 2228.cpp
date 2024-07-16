#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int N, M;
vector<int> inputs;

vector<vector<int> > dp;
vector<int> sum;

int main(){
    cin >> N >> M;
    inputs.assign(N+1, 0);
    sum.assign(N+1, 0);
    dp.assign(N+1,vector<int>(M+1,0));
    for(int i = 1 ; i <= N; i++){
        cin >> inputs[i];
        sum[i] = sum[i-1] + inputs[i];
    }
    for(int j = 1; j <= M; j++){
        dp[0][j] = -32768000;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1 ; j <= M; j++){
            int maxSum = -32768000;
            for(int k = 1; k <= i;k++){
                if(k == 1 && j == 1){
                    maxSum = max(maxSum, sum[i]);
                } else if(k >= 2){
                    maxSum = max(maxSum, dp[k-2][j-1] + sum[i] - sum[k-1]);
                }
            }
            dp[i][j] = max(dp[i-1][j], maxSum);
        }
    }

    cout << dp[N][M];
    
    
}
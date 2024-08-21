#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, K;
vector<vector<int> > inputs;
vector<vector<int> > sums;
vector<vector<int> > dp;

int solve(int remain, int g){
    if(remain == 0){
        return 0;
    }
    if(g >= 10){
        return 0;
    }
    if(dp[g][remain] != -1){
        return dp[g][remain];
    }

    int maxResult = solve(remain, g+1);

    for(int i = 1; i <= min(remain, (int)inputs[g].size());i++){
        int result = sums[g][i-1] + i*(i-1) + solve(remain-i,g+1);

        if(maxResult < result){
            maxResult = result;
        }
    }

    return dp[g][remain] = maxResult;
}
 
int main(){
    cin >> N >> K;
    inputs.assign(10, vector<int>(0));
    sums.assign(10, vector<int>(N+1,0));
    dp.assign(10, vector<int>(N+1,-1));
    
    for(int i = 0; i < N; i++){
        int C, G;
        cin >> C >> G;
        inputs[--G].push_back(C);
    }
    for(int i = 0; i < 10; i++){
        sort(inputs[i].rbegin(), inputs[i].rend());
    }
    for(int i = 0; i < 10; i++){
        if(!inputs[i].size()){
            continue;
        }
        sums[i].assign(inputs[i].size(), 0);
        sums[i][0] = inputs[i][0];
        for(int j = 1; j < inputs[i].size(); j++){
            sums[i][j] = sums[i][j-1] + inputs[i][j];
        }
    }

    cout << solve(K, 0);
}
#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000007
using namespace std;
int N;
vector<string> W;
vector<vector<long long> > dp;
string targetWord = "UNIST";

long long solve(int index, int strIndex){
    if(strIndex >= 5){
        return 1;
    }
    if(index >= N){
        return 0;
    }
    if(dp[index][strIndex] != -1){
        return dp[index][strIndex];
    }
    
    long long result = solve(index+1, strIndex);

    for(int i = 0; strIndex+i < 5;i++){
        if(targetWord[strIndex+i] != W[index][i]){
            break;
        }
        result = (result + solve(index+1, strIndex+i+1) % MOD)  % MOD;
    }

    return dp[index][strIndex] = result;

}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    W.assign(N,"");
    dp.assign(N, vector<long long>(5,-1));
    for(int i = 0; i < N; i++){
        cin >> W[i];
    }

    long long result = solve(0,0);
    cout << result;
}
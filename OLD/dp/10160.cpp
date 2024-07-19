#include<iostream>

using namespace std;

long long dp[1000001];
int N,K;

void solve(){
    dp[0]=1;
    for(int i  = 1;i <=N;i++){
        dp[i] = ((K*dp[i-1])-((i-5 >= 0 ? 2*dp[i-5] : 0))+(i-7 >= 0 ? dp[i-7] : 0))%(long long)1000000009;
        if(dp[i]<0) dp[i]+=1000000009;
    }
}
int main (){
    cin >> N >> K;

    solve();
    cout << dp[N];
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N, M;
vector<long long> W;

int main(){
    cin >> N >> M;
    W.assign(N, 0);
    long long sumResult = 0;
    for(int i = 0; i < N; i++){
        cin >> W[i];
        sumResult+=W[i];
        if(W[i] >= M){
            cout << "Free!";
            return 0;
        }
    }
    if(sumResult < M){
        cout << -1;
        return 0;
    }

    long long lo = 0;
    long long hi = N-1;

    vector<long long> dp(N,0);

    while(lo + 1 < hi){
        dp.assign(N, 0);
        long long mid = (lo + hi)/2;

        for(int i = 0 ; i < N; i++){
            if(i - mid - 1 < 0){
                dp[i] = max(i < 1 ? 0 : dp[i-1], W[i]);
            }else {
                dp[i] = max(dp[i-1], dp[i-mid-1] + W[i]);
            }
        }

        if(dp[N-1] >= M){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    cout << lo;


}
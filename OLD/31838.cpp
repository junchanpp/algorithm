#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long N,K;
vector<long long> inputs;
vector<long long> totalSum;
vector<long long> dp;
vector<long long> totalMax;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    inputs.assign(N,0);
    totalSum.assign(N,0);
    totalMax.assign(N+1,0);
    dp.assign(N+K,0);

    for(int i = 0; i < N; i++){
        cin >> inputs[i];
        if(i == 0){
            totalSum[i] = inputs[i];
        } else {
            totalSum[i] = totalSum[i-1] + inputs[i];
        }
    }

    for(int i = 0; i < N+K-1; i++){

        dp[i] = max(i <= 0 ? 0 : dp[i-1], (i-K < 0 ? 0 : totalMax[i-K]) + (i >= N ? totalSum[N-1]:totalSum[i]));
        if(i > N){
            continue;
        }
        totalMax[i] = max(i <= 0 ? 0 : totalMax[i-1], dp[i]-(i >= N ? totalSum[N-1]:totalSum[i]));
    }

    cout << dp[N+K-2];
}
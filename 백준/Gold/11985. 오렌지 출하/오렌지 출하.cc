#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

long long N, M, K;
vector<long long> A;
vector<long long> dp;//0~i까지 최소 비용

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;
    A.assign(N, 0);
    dp.assign(N, LLONG_MAX);

    //입력처리
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    for(int i = 0; i < N; i++){
        long long a = A[i];
        long long b = A[i];
        for(int j = i; j >= max(i-M+1, (long long)0); j--){
            a = max(a, A[j]);
            b = min(b, A[j]);
            long long costs = K + (i - j + 1) * (a - b);
            dp[i] = min(dp[i], (j >= 1 ? dp[j-1] : 0) + costs);
        }
    }

    cout <<  dp[N-1];
}
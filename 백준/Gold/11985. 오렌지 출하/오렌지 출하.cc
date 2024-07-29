#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

long long N, M, K;
vector<long long> A;
vector<vector<long long> > costs;//a~b까지 포장하는 비용
vector<long long> dp;//0~i까지 최소 비용

int main(){
    cin >> N >> M >> K;
    A.assign(N, 0);
    dp.assign(N, LLONG_MAX);
    costs.assign(N, vector<long long>(N,0));

    //입력처리
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    //cost 전처리
    for(int i = 0 ; i < N; i++){
        long long a = A[i];
        long long b = A[i];
        costs[i][i] = K;
        for(int j = i+1 ; j < min(i+M+1, N); j++){
            a = max(a, A[j]);
            b = min(b, A[j]);
            costs[i][j] = K + (j - i + 1) * (a - b);
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = max(i-M+1, (long long)0); j <= i; j++){
            dp[i] = min(dp[i], (j >= 1 ? dp[j-1] : 0) + costs[j][i]);
        }
    }

    cout <<  dp[N-1];
}
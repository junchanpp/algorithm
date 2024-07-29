#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int N;
vector<int> A;
vector<int> dp;

int solve(int index){
    if(index >= N){
        return 0;
    }
    if(dp[index] != INT_MIN){
        return dp[index];
    }

    int result = 0;

    for(int i = index + 1; i < N; i++){
        if(A[index] > A[i]){
            result = max(result, solve(i));    
        }
        
    }




    return dp[index] = result + A[index];
}

int main(){
    cin >> N;
    A.assign(N, 0);
    dp.assign(N, INT_MIN);
    for(int i = 0 ; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < N; i++){
        solve(i);
    }

    int result = 0;
    for(int i = 0 ; i < N; i++){
        result = max(result, dp[i]);
    }

    cout << result;


}
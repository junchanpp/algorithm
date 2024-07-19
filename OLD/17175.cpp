#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int main(){
    int n;
    cin >> n;
    dp.assign(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i-2] + dp[i-1] + 1) % 1000000007;
    }

    cout << dp[n];
}
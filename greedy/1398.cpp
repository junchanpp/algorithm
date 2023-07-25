#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int memo[100][3];
int mul[3] = {1,10,25};
int dp(int n, int index){
    if(memo[n][index] != -1)return memo[n][index];
    if(index == 0 || n ==0)return n;
    int min = 100;
    for(int i = 0; i*mul[index]<=n;i++){
        int count = dp(n-i*mul[index], index-1);
        if(min > i+count)min = i+count;
    }
    
    return memo[n][index] = min;
}

int solve(long long n){
    int count = 0;
    while(n > 0){
        count += dp(n%100,2);
        n = n/100;
    }
    return count;
}

int T;
int main(){

    cin >> T;

    fill(&memo[0][0], &memo[0][0]+100*3,-1);


    while(T--){
        long long N;
        cin >> N;
        cout << solve(N) << endl;
    }
}
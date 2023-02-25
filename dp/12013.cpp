#include<iostream>
#include <string.h>

using namespace std;

int N;
int arr[250];
int dp[250][250];

int solve(int s, int d){
    if(s == d)return arr[s];
    if(dp[s][d]>=0)return dp[s][d];
    int ret = 0;
    for(int i = s; i< d; i++){
        int a = solve(s,i);
        int b = solve(i+1,d);
        if(!a or !b)continue;
        if(a == b && a+1 > ret){
            ret = a+1;
        }
    }
    return dp[s][d] = ret;
}

int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i =0; i<N;i++){
        cin >> arr[i];
        dp[i][i]=arr[i];
    }
    int max = 0;
    for(int i = N-1; i>= 0;i--){
        for(int j = 0; j<N;j++){
            if(max < solve(i,j))max = solve(i,j);
        }
    }
    cout << max;
}
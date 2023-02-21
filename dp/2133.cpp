#include <iostream>

using namespace std;

int memo[31];

int solve(int n){
    if(memo[n]!=0)return memo[n];
    memo[2] = 3;
    memo[0] = 1;
    for(int i = 4; i <=n;i+=2){
        int sum = 0;
        sum += memo[i-2]*3;
        for(int j = 4; j<=i;j+=2){
            sum += memo[j-4]*2;
        }
        memo[i] =sum;
    }

    return memo[n];
}


int main (){
    int n;
    cin >>n;
    if(n%2 ==1){
        cout << 0;
        return 0;
    }

    int answer = solve(n);

    cout << answer;
}
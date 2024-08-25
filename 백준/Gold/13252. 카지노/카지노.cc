#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;

long long N, M, K;

map<pair<int, long long>, double> dp;

double solve(int round, long long n){
    if(n == 0){
        return 0;
    }
    if(round == 0){
        return 1;
    }
    if(dp.find(make_pair(round, n)) != dp.end()){
        return dp[make_pair(round, n)];
    }



    int count1Group = M - n % M;// n%M == 0인 그룹 개수
    int count2Group = n % M;// n%M != 0인 그룹 개수

    double result = (double)count1Group/M * solve(round-1, n - n/M) + (double)count2Group/M * solve(round-1, n - (n/M + 1));

    dp[make_pair(round, n)] = result;
    return result;
    
}

int main(){
    cin >> N >> M >> K;

    printf("%f", solve(K, N));


}
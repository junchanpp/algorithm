#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int memo[501][501];
int cost[501];
int sumMemo[501];
int sum1(int index1, int index2){
    if(memo[index1][index2]!=1e9)return memo[index1][index2];
    if(index1 == index2)return 0;
    if(index1+1 == index2)return cost[index1]+cost[index2];
    for(int i = index1; i<index2;i++){
        int result = sum1(index1,i)+sum1(i+1,index2);
        memo[index1][index2] = min(memo[index1][index2], result);
    }
    memo[index1][index2] += sumMemo[index2]-sumMemo[index1-1];
    return memo[index1][index2];
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int K;
        cin >> K;
        fill(&memo[0][0],&memo[0][0]+501*501,1e9);
        for(int i = 1; i <= K;i++){
            int temp;
            cin >> temp;
            cost[i]=temp;
            memo[i][i]= 0;
            sumMemo[i]= sumMemo[i-1]+temp;
        }
        cout << sum1(1,K) << endl;
    }
}
#include <iostream>
#include <vector>

using namespace std;

int N;
int memo[2001][2001];
int arr[2001];

int check(int s, int e){
    if(memo[s][e] != -1){
        return memo[s][e];
    }
    if(s-e <= 1 && s-e >= -1){
        return memo[s][e] = (arr[s] == arr[e]) ? 1 : 0;
    }

    return memo[s][e] = (arr[s] == arr[e]) ? check(s+1,e-1) : 0;
}

int main(){
    scanf("%d", &N);
    for(int i = 1 ; i<= N; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 1 ; i <= N; i++){
        for(int j = i; j <= N; j++){
            memo[i][j] = -1;
        }
    }
    int M;
    scanf("%d", &M);
    vector<int> ans;
    for(int i = 0; i < M; i++){
        int s,e;
        scanf("%d %d", &s , &e);
        ans.push_back(check(s,e));
    }

    for(int i  = 0 ; i < M; i++){
        printf("%d\n", ans[i]);
    }


}
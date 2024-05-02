#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > memo;//a: 사용한 가치, b: 회사 인덱스
vector<vector<bool> > visited;
vector<vector<int> > arr;

int solve(int cost, int index);

int main(){
    cin >> N >> M;

    arr.assign(N+1,vector<int>(M,0));//[a][b] : a 투자 금액 b 회사, return 값 : 얻을 가치
    memo.assign(N+1, vector<int>(M,0));
    visited.assign(N+1, vector<bool>(M,0));

    for(int i = 0 ; i < N; i++){
        int cost;
        cin >> cost;
        for(int j = 0; j < M; j++){
            cin >> arr[cost][j];
        }
    }
    int answer = 0;
    for(int i = 0 ; i <= N; i++){
        int value = solve(i,0)+ arr[i][0];
        if(value > answer){
            answer = value;
        }
    }
    cout <<answer << endl;
    vector<int> answers;
    int a = answer;
    int useCost = 0;
    for(int i = 0 ; i < M; i++){
        for(int j = 0; j <= N; j++){
            if(memo[j + useCost][i] + arr[j][i] == a){
                cout << j << " ";
                a -= arr[j][i];
                useCost += j;
                break;
            }
        }
    }
}


int solve(int cost, int index){//index번 회사까지 사용한 비용: cost
    if(cost == N){
        return 0;
    }
    if(index + 1 == M){
        return 0;
    }
    if(visited[cost][index]){
        return memo[cost][index];
    }
    visited[cost][index] = true;
    int earnedValue = 0;
    int remainCost = N - cost;
    for(int c = 0 ; c <= remainCost; c++){
        int nowValue = arr[c][index+1] + solve(c+cost,index+1);
        if(earnedValue < nowValue){
            earnedValue = nowValue;
        }
    }

    return memo[cost][index] = earnedValue;
}
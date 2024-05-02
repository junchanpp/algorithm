#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int solve(int K, int a);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int K, N;
    cin >> K >> N;

    vector<int> inputs(N);

    for(int i = 0 ; i < N; i++){
        cin >> inputs[i];
    }

    for(int i = 0 ; i < N; i++){
        int result = solve(K, inputs[i]);
        if(result == -1){
            cout << "NO" << endl;
        } else {
            cout << result << endl;
        }
    }
}

set<int> memo[9];
bool isVisited = false;

void calc(int K){
    if(isVisited){
        return;
    }
    isVisited = true;

    int initNum = 0;
    for(int i = 1; i <= 8; i++){
        initNum = initNum * 10 + K;
        memo[i].insert(initNum);
    }

    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= i ; j++){
            int index = i + j;
            if(index > 8){
                continue;
            }
            for(int a : memo[i]){
                for(int b : memo[j]){
                    memo[index].insert(a + b);
                    memo[index].insert(a * b);
                    if(a!=b) memo[index].insert(abs(a - b));
                    if(a > b) memo[index].insert(a / b);
                    else memo[index].insert(b / a);
                }
            }
        }
    }
}

int solve(int K, int a){
    calc(K);

    for(int i = 1; i <= 8; i++){
        if(memo[i].count(a)){
            return i;
        }
    }
    return -1;
}
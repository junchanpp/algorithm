#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
vector<vector<int> > inputs;
vector<int> bitmasks;
int maxBitmask;
vector<vector<int> > dp;//[i][j] i번째 줄, j만큼 비트마스킹

int count(int bitmask){
    int cnt = 0;
    while(bitmask != 0){
        if(bitmask%2){cnt++;}
        bitmask = bitmask>>1;
    }
    return cnt;
}

int merge(int personBitmask, int preBitmask){
    int newBitmask = 0;
    for(int i = 0; i < M; i++){
        if(personBitmask & (1 << i)){
            if(i != 0){newBitmask |= 1 << (i-1);}
            if(i != M-1){newBitmask |= 1 << (i+1);}
        }
    }

    return newBitmask | preBitmask;
}

bool check(int personBitmask){
    while(personBitmask != 0){
        if((3 & personBitmask) == 3){
            return true;
        }
        personBitmask = personBitmask >> 1;
    }
    return false;
}


int solve(int line, int initBitmask){
    if(line == 0){
        int personCount = 0;
        for(int i = 0 ; i <= maxBitmask; i++){
            if(initBitmask & i){
                continue;
            }
            if(check(i)){
                continue;
            }
            if(count(i) > personCount){
                personCount = count(i);
            }
        }
        return dp[line][initBitmask] = personCount;
    }
    if(dp[line][initBitmask] != -1){
        return dp[line][initBitmask];
    }
    int maxCount = 0;
    
    int preBitmask = bitmasks[line - 1];

    for(int i = 0; i <= maxBitmask; i++){
        if(initBitmask & i){
            continue;
        }
        if(check(i)){
            continue;
        }
        int newBitmask = merge(i, preBitmask);
        int personCount = count(i) + solve(line-1, newBitmask);
        if(maxCount < personCount){
            maxCount = personCount;
        }
    }

    return dp[line][initBitmask] = maxCount;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int C;
    cin >> C;
    vector<int> answers;
    while(C--){
        inputs.clear();
        dp.clear();
        bitmasks.clear();
        cin >> N >> M;
        inputs.assign(N, vector<int>(M, 0));
        dp.assign(N, vector<int>((1<<M), -1));
        bitmasks.assign(N, 0);
        for(int i = 0 ; i < N; i++){
            string s;
            cin >> s;
            for(int j = 0; j < M; j++){
                if(s[j] != '.'){inputs[i][j] = 1;}
            }
        }
        for(int i = 0 ; i < N; i++){
            int bitmask = 0;
            for(int j = 0; j < M; j++){
                if(inputs[i][j]){
                    bitmask |= 1 << j;
                }
                
            }
            bitmasks[i] = bitmask;
        }
        maxBitmask = (1 << M) -1;

        answers.push_back(solve(N-1, bitmasks[N-1]));
    }
    for(int i = 0 ; i < answers.size(); i++){
        cout << answers[i] << '\n';
    }
}
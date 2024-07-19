#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int N,K;

vector<int> S;
vector<int> num;
int sum = 0;
bool isCanUse[10];

bool isValidNum(int result, int index){
    string s = to_string(result);
    if(s.length() !=S[index]) return false;

    for(int i = 0; i < S[index]; i++){
        if(!isCanUse[s[i]-'0'])return false;
    }

    return true;
}

bool isOk(string realS[2]){
    int S1 = stoi(realS[0]);
    int S2 = stoi(realS[1]);

    if(!isValidNum(S1*S2, N-1)){
        return false;
    }
    
    for(int i = 2; i < N-1; i++){
        if(!isValidNum(S1 * (realS[1][N-2-i]-'0'),i)){
            return false;
        }
    }

    return true;
}

void solve(string realS[2], int s1len, int s2len){
    if(s2len == S[0]){
        sum += isOk(realS) ? 1 : 0;
        return;
    }

    int index1 = s1len == S[0] ? 1 : 0;
    int index2 = index1 == 0 ? s1len: s2len;

    for(int i = 0; i< K; i++){
        solve(realS[index1]+(num[i]+'0'), index1 == 0 ? s1len+1 : s1len, index1 == 1 ? s2len+1:s2len);
    }
    realS[index1].resize(index2);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    S.assign(N,0);
    for(int i = 0;i < N;i++){
        cin >> S[i];
    }

    cin >> K;
    
    for(int i = 0 ; i < K; i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
        isCanUse[temp] = true;
    }

    string realS[2];
    solve(realS,0,0);

    cout <<sum;
    
    return 0;
}
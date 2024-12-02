#include <iostream>
#include <vector>

using namespace std;

int N, M;
string S;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    cin >> M;
    cin >> S;

    long long answer = 0;

    int nowLength = 0;
    for(int i = 1; i < M - 1; i++){
        if(S[i-1] == 'I' && S[i] == 'O' && S[i+1] == 'I'){
            nowLength++;
            i++;
        }
        else if(nowLength >= N){
            answer = answer + (nowLength - N + 1);
            nowLength = 0;
        }
        else if(nowLength != 0){
            nowLength = 0;
        }
    }
    if(nowLength >= N){
        answer = answer + (nowLength - N + 1);
        nowLength = 0;
    }
    cout << answer;
}
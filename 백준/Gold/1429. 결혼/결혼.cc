#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

int solution(int N, int M, vector<vector<bool> > v);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;// 남자 N명, 여자 M명. 최대 12

    vector<vector<bool> > v(N,vector<bool>(M,false));

    for(int i = 0; i < N;i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            v[i][j] = s[j] - '0';
        }
    }

    cout <<  solution(N, M, v);

}

int solution(int N, int M, vector<vector<bool> > v){
    int allMarriedManBinary = 0;
    int allMarriedWomanBinary = 0;
    for(int i = 0 ; i < N; i++){
        allMarriedManBinary |= (1 << i);
    }
    for(int i = 0 ; i < M; i++){
        allMarriedWomanBinary |= (1 << i);
    }
    
    int marryCount = INT_MAX;
    for(int i = 0; i <= allMarriedManBinary; i++){
        int manCount = 0;
        for(int a = 0 ; a < N; a++){
            if(i & (1 << a)){
                manCount++;
            }
        }
        for(int j = 0 ; j <= allMarriedWomanBinary; j++){
            int womanCount = 0;

            for(int a = 0 ; a < M; a++){
                if(j & (1 << a)){
                    womanCount++;
                }
            }
            if(manCount + womanCount < min(2,min(N,M)) || manCount + womanCount > max(N,M) || manCount+womanCount >= marryCount){
                continue;
            }

            int checkMarriedManBinary = 0;
            int checkMarriedWomanBinary = 0;
            for(int a = 0; a < N; a++){
                for(int b = 0; b < M; b++){
                    if((v[a][b] && (i & (1 << a) || j & (1 << b)))){
                        checkMarriedManBinary |= (1 << a);
                        checkMarriedWomanBinary |= (1 << b);
                    }
                }
            }
            if(checkMarriedManBinary == allMarriedManBinary && checkMarriedWomanBinary == allMarriedWomanBinary){
                marryCount = manCount + womanCount;
            }
        }
    }

    return marryCount == INT_MAX ? -1 : marryCount;
}

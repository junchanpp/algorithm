#include <iostream>
#include <climits>

#define UNDEFINED LLONG_MIN
using namespace std;

int N;
long long scores[20][20];
int endBit;
long long totalSum = 0;

int main(){
    cin >> N;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> scores[i][j];
            totalSum+=scores[i][j];
        }
    }
    endBit = 1 << N;
    long long answer = UNDEFINED;
    for(int i = 0 ; i < endBit; i++){//end는 비트 단위로 색칠여부 판단, 행
       long long score2 = 0;
       for(int b = 0 ; b < N; b++){
        
        long long isCanFill = 0;
        long long sumIfFill = 0;
        long long sumIfNotFill = 0;
        for(int a = 0 ; a< N; a++){
            if((1 << a & i) == 1 << a){//나도 색칠
                isCanFill += scores[a][b];
                sumIfFill += scores[a][b];
            } else {
                isCanFill -= scores[a][b];
                sumIfNotFill += scores[a][b];
            }
        }
        if(isCanFill > 0){//색칠해서 점수 계산
           score2 += sumIfFill;
        }else {
            score2 += sumIfNotFill;
        }
       }

       long long score1 = totalSum - score2;
       if(score1 > answer)answer = score1;
    }

    cout << answer;
}
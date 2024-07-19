#include <iostream>

using namespace std;

int memo[10001] = {0,};
int N, M;

long long solve(int index){//index(m)에서 블럭 생성
    if(index > M){
        return 0;
    }
    else if(index == M){
        return 1;
    } else if(memo[index] != 0){
        return memo[index];
    }

    //항상 현시점에서 블럭을 1~N 크기까지 생성한다.
    //마지막 N크기를 생성할 때에는 NxN 크기 블럭 하나를 생성할 경우가 아닌, NxN을 세로로 여러 블럭으로 만드는 경우를 생각해서 구현한다.
    int sum = 0;

    for(int blockSize = 1; blockSize <= N; blockSize++){
        if(index + blockSize > M){
            break;
        }
        sum = (sum + solve(index+blockSize))% 1999;
        if(blockSize == N && memo[M-N] != 0){
            sum = (sum + (((memo[M-N]-1)/2)% 1999) * (memo[index+N]% 1999));
        }
    }

    if(index == M-N){//index == M-N일 때 한번 실행
        sum = ((sum*2)-1)%1999;
    }

    return memo[index] = sum;

}

int main(){
    cin >> N >> M;

    if(M >= N){
        solve(M-N);
    }

    cout << solve(0) % 1999;

    return 0;
}
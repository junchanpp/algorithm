#include <iostream>
#include <string.h>

using namespace std;
long long solve(long long prevNumber, long long n);

long long memorized[101][1010];

int main(){
    long long n;
    cin >> n;

    long long answer = 0;
    for(int i = 1; i < 10; i++) {
        answer = (answer % 1000000000 + solve(i,n-1) % 1000000000) % 1000000000;
    }

    cout << answer;

    return 0;
}

// prevNumber : 마지막으로 채워진 number
// n : 채워야 하는 남은 개수
long long solve(long long prevNumber, long long n) {

    //이미 답을 구한 적 있으면 재사용
    if(memorized[prevNumber][n] != 0){
        return memorized[prevNumber][n] % 1000000000;
    }


    // prevNumber가 0~9 사이에 없으면 방법이 없다고 판단
    if(prevNumber < 0 || prevNumber > 9) {
        return 0;
    }
    // 채워야 하는 개수가 0이면 그때 방법이 1개 있다고 판단.
    if(n==0) {
        return 1;
    }

    long long answer = ((solve(prevNumber-1, n-1) % 1000000000) + (solve(prevNumber+1, n-1) % 1000000000)) % 1000000000;

    memorized[prevNumber][n] = answer % 1000000000;
    return answer % 1000000000;
}
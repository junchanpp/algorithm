#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(int N);
vector<int> memo;

int main(){
    int N; // 최대 백만
    cin >> N;
    memo.assign(N+1,0);

    int answer = solve(N);

    cout << ((answer == 0) ? -1 : answer);
}

int getNumFromSubString(int start, int end, int N){
    int temp = N;
    int num = 0;
    while(start != 0){
        temp /= 10;
        start--;
        end--;
    }
    int nextLength = 1;
    while(end != 0){
        int v = temp % 10;
        temp /=10;
        num += v*nextLength;
        nextLength*=10;
        end--;
    }

    return num;
}

int solve(int N){
    for(int i = 10 ; i <= N; i++){
        int length = 0;
        int temp = i;
        while(temp != 0){
            temp/=10;
            length++;
        }

        bool isWin = false;

        for(int j = 1; j < length; j++){
            for(int k = 0 ; k < length - j +1;k++){
                int nowNum = getNumFromSubString(k,k+j,i);// [k,k+j)임을 유의
                if(nowNum == 0){
                    continue;
                }
                if(!memo[i-nowNum]){
                    if(i == N){
                        return nowNum;
                    }
                    isWin = true;
                    break;
                }
            }
            if(isWin){
                break;
            }
        }
        memo[i] = isWin;
    }

    return memo[N];
}
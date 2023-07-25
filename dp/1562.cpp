#include <iostream>

using namespace std;

int N;
long long memo[10][101][1024];
long long solve(int prevNum, int count, int checkBit){
    if(prevNum > 9 || prevNum < 0) return 0;
    if(memo[prevNum][count][checkBit] != -1) return memo[prevNum][count][checkBit];
    if(count ==0){
        if(checkBit == 0)return 1;
        else return 0;
    }
    return memo[prevNum][count][checkBit] =
     (solve(prevNum+1, count-1, checkBit & ~(1 << (prevNum+1)))%1000000000 + 
     solve(prevNum-1, count-1, checkBit & ~(1 << (prevNum-1)))%1000000000)%1000000000;

}

int main(){
    cin >> N;
    long long sum = 0;
    for(int i = 0; i <= 9; i++){
        for(int j = 0 ; j <= N; j++){
            for(int k = 0 ; k <= 1023; k++){
                memo[i][j][k] = -1;
            }
        }
    }
    for(int i = 1; i<= 9; i++){
        sum = (sum+solve(i,N-1, 0b1111111111 & ~ (1 << i)))%1000000000;
    }

    cout << sum << endl;
}
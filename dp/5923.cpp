#include <iostream>
#include <string>

using namespace std;
int map[9][9];
int memo[9][0xFFFF+1];

int solve(int row, int prevBitmask, int nowCol, int nowBitmask){//bitmask에서 0은 홀수열, 1은 짝수열 의미
    if(row == 9){
        
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 9; j++){
            map[i][j] = s[j]-'0';
        }   
    }

    int ans = solve(0,0,0,0);
}
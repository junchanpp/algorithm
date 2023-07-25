#include<iostream>
#include<algorithm>
#define MOD 9901
//13:55:00
using namespace std;
int N, M;
int memo[14][0x3FFF+1];
int bitmask_accepted;

bool isValid(int bitmask){
    for(int i = 0 ; i < N-1; i++){
        if((bitmask & (3 << i)) == 0){
            bitmask = bitmask | (3 << i);
        }
    }
    return bitmask == bitmask_accepted;
}

int solve(int row, int startI, int prevBitmask, int nowBitmask){
    if(row == M-1){
        return isValid(prevBitmask) ? 1 : 0;
    }
    if(memo[row][prevBitmask] != -1){
        return memo[row][prevBitmask];
    }
    int ans = 0;
    for(int i = startI ; i < N; i++){
        if(!(prevBitmask & (1 << i)))ans=(ans+(solve(row,i+1, prevBitmask, nowBitmask | (1 << i)))%MOD)%MOD;
    }

    if(isValid(nowBitmask | prevBitmask))ans=(ans+(solve(row+1,0,nowBitmask,0x00)%MOD))%MOD;
    if(nowBitmask == 0x00)memo[row][prevBitmask] = ans;

    return ans;
}

int main(){
    cin >> N >> M;
    fill(&memo[0][0], &memo[0][0]+sizeof(memo)/sizeof(int), -1);

    bitmask_accepted = 0;
    for(int i = 0; i < N; i++){
        bitmask_accepted |= 1 << i;
    }

    int ans = solve(0,0,0x00,0x00);
    cout << ans << endl;
}
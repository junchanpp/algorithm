#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cat[16][2];
int memo[16][0xFFFF+1];
int completeBitmask = 0;

int solve(int catIndex, int bitmask){
    if(bitmask == completeBitmask){
        return cat[catIndex][0] + cat[catIndex][1];
    }
    if(memo[catIndex][bitmask] != -1){
        return memo[catIndex][bitmask];
    }

    int min = -1;
    for(int i = 0 ; i < N ; i++){
        if(!(bitmask & (1 << i))){
            int ans = solve(i, bitmask | 1<< i);
            int distance = ans + abs(cat[catIndex][0]-cat[i][0]) + abs(cat[catIndex][1]-cat[i][1]);
            if(min > distance || min == -1){
                min = distance;
            }
        }
    }

    return memo[catIndex][bitmask] = min;
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N; i++){
        completeBitmask |= 1 << i;
    }
    fill(&memo[0][0], &memo[0][0]+(16)*(0xFFFF+1),-1);

    for(int i = 0 ; i < N; i++){
        scanf("%d %d", &cat[i][0], &cat[i][1]);
    }

    int min = -1;
    for(int i = 0 ; i < N; i++){
        int ans = solve(i, 1 << i);
        if(min == -1 || min > ans + cat[i][0] + cat[i][1])min = ans + cat[i][0] + cat[i][1];
    }

    cout << min;

    return 0;
}
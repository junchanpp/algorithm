#include <iostream>
#include <algorithm>
using namespace std;

int N;

int work[21][21];
int memo[21][0xFFFFF+1];

int solve(int personIndex, int bitmask){
    if(personIndex == N){
        return 0;
    }
    if(memo[personIndex][bitmask] != -1){
        return memo[personIndex][bitmask];
    }

    int min = -1;

    for(int i = 0 ; i < N; i++){
        if(!(bitmask & (1 << i))){
            int ans = solve(personIndex+1, bitmask | 1<<i);
            if(ans+work[personIndex][i] < min || min == -1)min = ans + work[personIndex][i];
        }
    }

    return memo[personIndex][bitmask] = min;
}

int main(){
    cin >> N;

    fill(&memo[0][0], &memo[0][0]+(21*(0xFFFFF+1)), -1);

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            scanf("%d", &work[i][j]);
        }
    }

    int answer = solve(0,0);

    cout << answer << endl;

    return 0;

}
#include <iostream>
#include <algorithm>
//12:47:00
using namespace std;

int N;
int cost[16][16];
int memo[16][0xFFFF+1];
int bitmaskAllvisited;
int startNode;

int solve(int node, int bitmask){
    if(bitmask == bitmaskAllvisited){
        return cost[node][startNode];
    }
    if(memo[node][bitmask]!=-1){
        return memo[node][bitmask];
    }
    int minCost = 0;
    for(int i = 0 ; i < N ; i++){
        if(!(bitmask & (1 << i)) && cost[node][i] != 0){
            int nowCost = solve(i, bitmask | (1 << i));
            if(nowCost != 0 && (minCost == 0 || nowCost+ cost[node][i] < minCost))minCost = nowCost+cost[node][i];
        }
    }
    return memo[node][bitmask] = minCost;
}


int main(){
    for(int i = 0 ; i < 16; i++){
        for(int j = 0 ; j < 0xFFFF+1; j++){
            memo[i][j] = -1;
        }
    }
    cin >> N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j< N; j++){
            cin >> cost[i][j];
        }
    }

    bitmaskAllvisited = 0;
    for(int i = 0 ; i < N; i++){
        bitmaskAllvisited = bitmaskAllvisited | (1 << i);
    }

    int minCost = 0;
    for(int i = 1 ; i< N;i++){
        startNode = 15;
        int ans = solve(15, 1 << 15);
        cout << i << " " << (1 << i) << " " << ans << " " << bitmaskAllvisited << endl;
        if(ans < minCost || minCost == 0)minCost = ans;
    }

    cout << minCost << endl;
}
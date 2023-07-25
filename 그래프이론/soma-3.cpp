#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100001

using namespace std;

vector<int> height;
vector<int> position;
int N,M;

int memo [21][21][2];

int solve(int n,int m, bool isStart = false){
    if(memo[n][m][isStart] != -1)return memo[n][m][isStart];
    int min = -1;
    for(int d=0;d<=m;d++){
        int count = 1;
        int i = n+d+1;
        while(i <N){
            if(position[n]+height[n] < position[i]){
                if(!isStart)break;
                else{
                    if(count <solve(i,m-d,true))count = solve(i,m-d,true);
                    break;
                }
            }
            int result = solve(i,m-d);
            count+=result;
            i+=result;
        }

        if(min == -1 ||min > count)min = count;//뒤로 d개 지웠을 때,최대 불안정도
    }
    memo[n][m][isStart] = min;
    return min;
}


int main(){
    cin >> N >> M;// N 은 최대 10, M은 N보다 작음
    for(int i = 0; i < N;i++){
        int temp;
        cin >> temp;
        position.push_back(temp);
    }
    for(int i = 0; i < N;i++){
        int temp;
        cin >> temp;
        height.push_back(temp);
    }
    fill(&memo[0][0][0], &memo[0][0][0]+21*21*2, -1);
    int answer = INF;
    for(int i = 0; i<=M;i++){
        if(answer > solve(i,M-i,true))answer = solve(i,M-i, true);
    }
    cout << answer << " " << endl;
}
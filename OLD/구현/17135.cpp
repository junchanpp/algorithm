#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;
int N,M,D;//N이 행의 수, M이 열의 수
bool monster[16][16];
int answer = 0;

int getDistance(int y1,int x1, int y2, int x2){
    return abs(x1-x2)+abs(y1-y2);
}

int solve(vector<int> combi){
    bool monster_copy[N][M];
    for(int i = 0; i < N ;i++){
        for(int j = 0; j<M;j++){
            monster_copy[i][j] = monster[i][j];
        }
    }
    int i = 0;
    int count = 0;
    while(i <N){
        set<pair<int, int> > target;

        for(int a = 0; a< 3; a++){
            int minDistance = 100000;
            pair<int,int> minIndex;
            for(int k = 0;k<M;k++){
                for(int j = 0; j <N;j++){
                    if(monster_copy[j][k]==1){
                        if(getDistance(N,combi[a],j,k) <= D && getDistance(N,combi[a],j,k) < minDistance){
                            minDistance = getDistance(N,combi[a],j,k);
                            minIndex = make_pair(j,k);
                        }
                    }
                }
            }
            if(minDistance!= 100000){
                target.insert(minIndex);
            }
        }
        for(set<pair<int,int> >::iterator iter = target.begin(); iter != target.end(); iter++){
            monster_copy[(*iter).first][(*iter).second] = 0;
            count++;
        }
        for(int j = N-1; j>=0;j--){
            for(int k =0; k<M;k++){
                if(j ==0){
                    monster_copy[j][k] = 0;
                    continue;
                }
                monster_copy[j][k] = monster_copy[j-1][k];
            }
        }
        i++;

    }

    return count;
}

void comb(int n, int r,int pos, vector<int> arr, vector<int> combi){
    if(combi.size() == r){
        int nowAnswer = solve(combi);
        if(answer < nowAnswer)answer = nowAnswer;
        return;
    }
    for(int i = pos; i < n;i++){
        combi.push_back(arr[i]);
        comb(n,r,i+1,arr, combi);
        combi.pop_back();
    }
    return;
}

int main(){
    cin >> N >> M >> D;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < M;j++){
            cin >> monster[i][j];
        }
    }
    vector<int> arr;
    for(int i = 0; i<M;i++){
        arr.push_back(i);
    }
    vector<int> combi;

    comb(M,3,0,arr, combi);

    cout << answer;
}
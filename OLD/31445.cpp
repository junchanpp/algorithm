#include <iostream>
#include <vector>
#include <queue>
#define MOD_NUM 1000000007

using namespace std;

vector<int> indegree;
vector<long long> memo;
vector<vector<int> > arr;
vector<vector<int> > rarr;

long long sum(long long x, long long y){
    return ((x % MOD_NUM) + (y % MOD_NUM)) % MOD_NUM;
}



int main(){
    int N, M;
    cin >> N >> M;
    arr.assign(N+1, vector<int>(0));
    rarr.assign(N+1, vector<int>(0));

    memo.assign(N+1, 1); // 기본으로 1명이상이기에 1개의 경우의수를 갖고 있음

    indegree.assign(N+1,0);
    for(int i = 0 ; i < M; i++){
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        rarr[y].push_back(x);
        indegree[y]++;
    }
    queue<int> q;

    for(int i = 1 ; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    long long answer = 0;

    while(!q.empty()){
        int index = q.front();
        q.pop();
        vector<bool> visited(N+1, false);

        answer = sum(answer, memo[index]);
        queue<int> subQ;

        for(int i = 0 ; i < arr[index].size(); i++){
            int nextIndex = arr[index][i];
            
            visited[nextIndex] = true;
            subQ.push(nextIndex);
        
            if(--indegree[nextIndex] == 0){
                q.push(nextIndex);
            }
        }

        while(!subQ.empty()){
            int nextIndex = subQ.front();
            subQ.pop();
            memo[nextIndex] = sum(memo[nextIndex], memo[index]);
            for(int i = 0 ; i < arr[nextIndex].size(); i++){
                int nx2Index = arr[nextIndex][i];
                if(visited[nx2Index] == false){
                    subQ.push(nx2Index);
                    visited[nx2Index] = true;
                }
            }
        }
    }

    cout << answer;

    return 0;
}
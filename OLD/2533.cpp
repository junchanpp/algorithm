#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int N;
vector<vector<int> > edge;
vector<int> indegree;
vector<int> isVisited;
vector<vector<int> > memo;

int main(){
    cin >> N;
    edge.assign(N+1,vector<int>(0));
    indegree.assign(N+1,0);
    isVisited.assign(N+1,0);
    memo.assign(N+1,vector<int>(2,0));

    for(int i = 0 ; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 1 ; i <= N; i++){
        if(indegree[i] == 1){
            q.push(i);
        }
    }

    int lastQueueIndex;

    while(!q.empty()){
        int currentIndex = q.front();
        q.pop();
        isVisited[currentIndex] = true;
        int needTurnOnCost = 0;
        int needJustCost = 0;
        for(int i = 0 ; i < edge[currentIndex].size(); i++){
            int index = edge[currentIndex][i];
            if(isVisited[index]){
                int prevIndex = index;
                needJustCost += memo[prevIndex][1];
                // needTurnOnCost += memo[prevIndex][0];
                needTurnOnCost += min(memo[prevIndex][0], memo[prevIndex][1]);
            } else {
                int nextIndex = index;
                if(--indegree[nextIndex] <= 1){
                    q.push(nextIndex);
                    lastQueueIndex = nextIndex;
                }
            }
        }

        memo[currentIndex][0] = needJustCost;
        memo[currentIndex][1] = needTurnOnCost+1;
    }
    cout << min(memo[lastQueueIndex][0], memo[lastQueueIndex][1]);

}
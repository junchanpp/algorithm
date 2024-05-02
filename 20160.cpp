#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>

#define MAX_NUM 0x7f7f7f7f7f7f

using namespace std;

int V, E;
vector<vector<long long> > costMap;
vector<vector<pair<int, long long> > > costPairs;
vector<bool> isSolved;


struct cmp{
    bool operator()(pair<int, long long>& a, pair<int, long long>& b){
        return a.second  > b.second;
    }
};

vector<long long> solve(int start){

    vector<long long> memo(V+1, MAX_NUM);
    memo[start] = 0;
    priority_queue<pair<int, long long>, vector<pair<int, long long> >, cmp> pq;
    pq.push(make_pair(start,0));

    while(!pq.empty()){
        int index = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(memo[index] < cost){
            continue;
        }
        for(int i = 0; i < costPairs[index].size(); i++){
            int nextIndex = costPairs[index][i].first;
            int nextCost = cost + costPairs[index][i].second;
            if(memo[nextIndex] > nextCost){
                memo[nextIndex] = nextCost;
                pq.push(make_pair(nextIndex, nextCost));
            }
        }
    }
    return memo;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> V >> E;

    costMap.assign(V+1,vector<long long>(V+1, MAX_NUM));
    costPairs.assign(V+1, vector<pair<int, long long> >(0));
    
    int answer = INT_MAX;
    for(int i = 0 ; i < V; i++){
        costMap[i][i] = 0;
    }

    for(int i = 0 ; i < E ; i++){
        int u, v, w;
        cin >> u >> v >> w;
        costMap[u][v] = w;
        costMap[v][u] = w;
        costPairs[u].push_back(make_pair(v,w));
        costPairs[v].push_back(make_pair(u,w));
    }

    vector<int> targetRouteList(10);
    for(int i = 0 ; i < 10; i++){
        cin >> targetRouteList[i];
    }
    int start;
    cin >> start;

    if(targetRouteList[0] == start){
        answer = start;
    }

    vector<long long> cost = solve(start);

    long long totalTargetCost = 0;
    int i = 0;
    while(1){
        int prevNode = targetRouteList[i];
        vector<long long> targetCost = solve(prevNode);
        while(i + 1 < 10 && targetCost[targetRouteList[i + 1]] == MAX_NUM){
            i++;
        }
        if(i + 1 >= 10){
            break;
        }
        i++;
        totalTargetCost += targetCost[targetRouteList[i]];
        int nextNode = targetRouteList[i];

        if(totalTargetCost >= cost[nextNode]){
            answer = min(answer, nextNode);
        }
    }
    if(answer != INT_MAX){
        cout << answer << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
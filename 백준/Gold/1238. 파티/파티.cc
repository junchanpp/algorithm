#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, X;
vector<vector<pair<int, int> > > edges;//edges[s] = {e, cost}
vector<int> memo;
vector<int> costs;


void solve1(int e){
    memo.clear();
    memo.assign(N,INT_MAX);


    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, X-1));
    memo[X-1] = 0;

    while(!pq.empty()){
        int cost = pq.top().first * -1;
        int prev = pq.top().second;
        pq.pop();
        if(memo[prev] < cost){
            continue;
        }
        for(int i = 0 ; i < edges[prev].size();i++){
            int nextCost = cost + edges[prev][i].second;
            int nextIndex = edges[prev][i].first;
            if(memo[nextIndex] > nextCost){
                memo[nextIndex] = nextCost;
                pq.push(make_pair(-1 * nextCost, nextIndex));
            }
        }
    }
}

int solve2(int s, int e){
    memo.clear();
    memo.assign(N,INT_MAX);


    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, s));
    memo[s] = 0;

    while(!pq.empty()){
        int cost = pq.top().first * -1;
        int prev = pq.top().second;
        pq.pop();
        if(memo[prev] < cost){
            continue;
        }
        for(int i = 0 ; i < edges[prev].size();i++){
            int nextCost = cost + edges[prev][i].second;
            int nextIndex = edges[prev][i].first;
            if(memo[nextIndex] > nextCost){
                memo[nextIndex] = nextCost;
                pq.push(make_pair(-1 * nextCost, nextIndex));
            }
        }
    }

    return memo[e];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> X;//X로부터의 모든 점의 최단 거리. 다익스트라 문제 N^2;
    edges.assign(N, vector<pair<int,int> >(0));
    memo.assign(N,INT_MAX);
    costs.assign(N, 0);
    

    for(int i = 0 ; i < M; i++){
        int s, e, cost;
        cin >> s >> e >> cost;
        s--;
        e--;
        edges[s].push_back(make_pair(e,cost));
    }
    
    solve1(X-1);

    for(int i = 0; i < N; i++){
        costs[i] = memo[i];
    }

    int maxIndex = 0;

    for(int i = 0; i < N; i++){
        costs[i] += solve2(i, X-1);
        if(costs[maxIndex] < costs[i]){
            maxIndex = i;
        }
    }

    cout << costs[maxIndex];
    


}
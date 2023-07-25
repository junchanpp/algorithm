#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 9223372036854775800

using namespace std;

long long cost[10010][21];
vector<pair<int, int> > road[10001];

int main(){
    int N, M, K;
    cin >> N >> M >>K;
    fill(&cost[0][0], &cost[0][0]+10010*21,INF);

    for(int i = 0 ; i < M ; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        road[temp1].push_back(make_pair(temp2,temp3));
        road[temp2].push_back(make_pair(temp1,temp3));
    }
    priority_queue< pair<long long,pair<int, int> >, vector< pair<long long,pair<int, int> > >, greater< pair<long long,pair<int, int> > > > pq;
    pq.push(make_pair(0,make_pair(1,K)));
    while(!pq.empty()){
        pair<long long ,pair<int, int> > cur = pq.top();
        pq.pop();
        long long curCost = cur.first;
        int curPoint = cur.second.first;
        int curK = cur.second.second;
        if(cost[curPoint][curK] <= curCost)continue;
        cost[curPoint][curK] = curCost;
        vector<pair<int, int> > curRoad = road[curPoint];
        for(int i = 0 ; i < curRoad.size();i++){
            long long newCost = curCost + curRoad[i].second;
            int newPoint = curRoad[i].first;
            pq.push(make_pair(newCost,make_pair(newPoint,curK)));
            if(curK > 0) pq.push(make_pair(curCost,make_pair(newPoint,curK-1)));
        }
    }
    long long min = cost[N][0];
    for(int i  = 1 ; i <= K; i++){
        if(min > cost[N][i])min = cost[N][i];
    }
    cout << min;
}
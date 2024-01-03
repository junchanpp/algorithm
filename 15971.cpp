#include <iostream>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

int N;
int startNode, endNode;
vector<vector<pair<int, int> > > v;
vector<int> visited;
int sol = 0;

void dfs(int index, int sum, int maxDist){
    if(sol == 1){
        return;
    }
    if(visited[index]==1){
        return;
    }
    visited[index] = 1;

    if(index == endNode){
        cout << sum - maxDist;
        sol = 1;
        return;
    }

    int size = v[index].size();
    for(int i = 0 ; i < size; i++){
        dfs(v[index][i].first, sum + v[index][i].second, max(maxDist, v[index][i].second));
    }
    return;
}

int main(){
    cin >> N >> startNode >> endNode;

    v.resize(N+1);
    visited.resize(N+1);

    for(int i = 0 ; i < N-1; i++){
        int node1, node2, dist;
        cin >> node1 >> node2 >> dist;
        v[node1].push_back(make_pair(node2,dist));
        v[node2].push_back(make_pair(node1,dist));
    }

    dfs(startNode,0,0);
}
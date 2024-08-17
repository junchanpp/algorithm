#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

int N, M, S;
vector<int> parent;
vector<pair<int, pair<int, int> > > edges;

int find(int a){
    if(parent[a] < 0){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    
    parent[a] += parent[b];
    parent[b] = a;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> S;
    edges.assign(N+1, make_pair(0,make_pair(0,0)));
    parent.assign(N+1, -1);
    
    for(int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u,v)));
    }
    sort(edges.begin(), edges.end());


    for(int i = 0 ; i < N; i++){
        int A;
        cin >> A;
    }

    int totalCost = 0;

    for(int i = 0; i < edges.size(); i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(find(a) == find(b)){
            continue;
        }
        totalCost += cost;
        merge(a,b);
    }

    cout << totalCost;

}
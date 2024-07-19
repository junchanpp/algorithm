#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

typedef struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
} cmp;

vector<int> solve(int V, int E, int K, vector<vector<pair<int, int> > > arr);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int V, E;
    int K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int> > > arr(V+1);//first: 도착 정점의 번호, second: 가중치

    for(int temp = 0 ; temp < E; temp++){
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v,w));
    }

    vector<int> answers = solve(V,E,K,arr);

    for(int i = 1 ; i <= V; i++){
        if(answers[i] == INT_MAX){
            cout << "INF" << endl;
        } else {
            cout << answers[i] << endl;
        }
    }
}


vector<int> solve(int V, int E, int K, vector<vector<pair<int, int> > > arr){
    vector<int> answers(V+1, INT_MAX);
    answers[K] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> pq;
    
    pq.push(make_pair(K,0));
    while(!pq.empty()){
        int index = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(answers[index] != cost){
            continue;
        }
        for(int i = 0 ; i < arr[index].size(); i++){
            int nextIndex = arr[index][i].first;
            int nextCost = arr[index][i].second + cost;
            if(answers[nextIndex] > nextCost){
                answers[nextIndex] = nextCost;
                pq.push(make_pair(nextIndex, nextCost));
            }
        }
    }


    return answers;
}
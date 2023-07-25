#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int> > edge[10001];//first: 자식 노드, second: 가중치
int dis = 0;
int N;

int dfs(int n){
    if(edge[n].empty()){return 0;}
    priority_queue<int> pq;
    for(int i = 0 ; i < edge[n].size(); i++){
        pq.push(dfs(edge[n][i].first)+edge[n][i].second);
    }
    int max1 = pq.top();
    if(pq.size()>=2){
        pq.pop();
        int max2 = pq.top();
        if(dis < max1+max2)dis = max1+max2;
    }else {
        if(dis < max1)dis = max1;
    }
    return max1;
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N-1; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        edge[temp1].push_back(make_pair(temp2,temp3));
    }

    int answer = dfs(1);
    
    cout << dis;
}
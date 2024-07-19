#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int N,M,R;
    cin >> N >> M >> R;
    vector<bool> isVisited(N+1, 0);
    vector<vector<int> > edges(N+1, vector<int>());
    vector<int> answers(N+1,0);

    for(int i = 0 ; i < M; i++){
        int s, e;
        cin >> s >> e;

        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    queue<int> q;
    isVisited[R] = true;
    int count = 1;
    q.push(R);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        answers[node] = count++;
        sort(edges[node].begin(), edges[node].end());

        for(int i = 0 ; i < edges[node].size(); i++){
            int nextNode = edges[node][i];
            if(isVisited[nextNode]){
                continue;
            }
            isVisited[nextNode] = true;
            q.push(nextNode);
        }
    }

    for(int i = 1; i < answers.size();i++){
        cout << answers[i] << '\n';
    }


}
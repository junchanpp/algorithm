#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> inputs;
vector<vector<int> > edges;
vector<int> visited;
int N;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    inputs.assign(N,0);
    visited.assign(N,0);
    edges.assign(N,vector<int>(0));
    for(int i = 0; i < N - 1; i++){
        int s,e;
        cin >> s >> e;
        s--;e--;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }
    for(int i = 0 ; i < N; i++){
        cin >> inputs[i];
        inputs[i]--;
    }

    queue<int> q;

    q.push(0);
    if(inputs[0] != 0){
        cout << 0;
        return 0;
    }
    visited[0] = 1;

    int checkIndex = 1;

    while(!q.empty()){

        int size = q.size();

        for(int a = 0; a < size; a++){
            int cur = q.front();
            q.pop();


            set<int> newVisited;
            

            for(int i = 0 ; i < edges[cur].size(); i++){
                int nextCur = edges[cur][i];
                if(visited[nextCur]){
                    continue;
                }
                visited[nextCur] = 1;
                newVisited.insert(nextCur);
            }
        
            for(int visitedSize = checkIndex + newVisited.size(); checkIndex < visitedSize; checkIndex++){
                if(newVisited.find(inputs[checkIndex]) == newVisited.end()){
                    cout << 0;
                    return 0;
                }
                q.push(inputs[checkIndex]);
            }


        }
    }

    cout << 1;

}
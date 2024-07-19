#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int> > inputs;
vector<vector<vector<bool> > > isVisited;
int dn[] = {0,0,1,-1};
int dm[] = {1,-1,0,0};

typedef struct Node{
    int count;
    int n;
    int m;
    bool isBroken;
    Node(int count, int n, int m, bool isBroken):count(count),n(n),m(m),isBroken(isBroken){}
}Node;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    inputs.assign(N,vector<int>(M,0));
    isVisited.assign(N,vector<vector<bool> >(M,vector<bool>(2,0)));
    
    for(int i  = 0 ; i <  N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            inputs[i][j] = s[j]-'0';
        }
    }

    queue<Node> q;
    q.push(Node(1,0,0,0));

    while(!q.empty()){
        int count = q.front().count;
        int n = q.front().n;
        int m = q.front().m;
        bool isBroken = q.front().isBroken;
        if(n == N-1 && m == M-1){
            cout << count;
            return 0;
        }

        q.pop();

        for(int i = 0 ; i  < 4; i++){
            int nextN = n + dn[i];
            int nextM = m + dm[i];
            if(nextN > N-1 || nextN < 0 || nextM > M-1 || nextM < 0){
                continue;
            }
            
            if(inputs[nextN][nextM] == 1){
                if(isBroken || isVisited[nextN][nextM][true]){
                    continue;
                }
                q.push(Node(count+1, nextN, nextM, true));
                isVisited[nextN][nextM][true] = true;
            } else {
                if(isVisited[nextN][nextM][isBroken]){
                    continue;
                }
                q.push(Node(count+1, nextN, nextM, isBroken));
                isVisited[nextN][nextM][isBroken] = true;
                isVisited[nextN][nextM][true] = true;
            }
        }
    }

    cout << -1;
    return 0;
}
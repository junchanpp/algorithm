#include <iostream>
#include <queue>
using namespace std;
int N, M, K;
vector<int> v[500001];
int inDegree[500001]={0,};

int memo[500001];

bool visited[500001]={0,};
int count[500001]={0,};

int solve(int node, int rootCntAdded){
    if(node == N)return 1;
    if(rootCntAdded > 120)return 0;
    if(memo[node] != -1)return memo[node];

    int nodeCnt = 0;
    for(int i = 1; i <=N; i++){
    }
}

int main(){
    cin >> N >> M >> K;
    for(int i = 1 ; i <= N; i++)memo[i]= -1;

    for(int i = 0 ; i < M; i++){
        int U, V;
        scanf("%d %d", &U, &V);
        if(U==V)continue;
        v[U].push_back(V);
        inDegree[V]++;
    }
    int result = 0;
    queue<int> q;
    q.push(1);

    count[1]=1;

    while(!q.empty()){
        int nodeNum = q.front();
        int nodeCount = count[nodeNum];

        q.pop();
        
        for(int i = 0 ; i< v[nodeNum].size();i++){
            inDegree[v[nodeNum][i]]--;
            count[v[nodeNum][i]]+=nodeCount;
            if(inDegree[v[nodeNum][i]]==0){
                q.push(v[nodeNum][i]);
            }
        }
    }
    int nowCount = count[N];

    solve(1,0);
}
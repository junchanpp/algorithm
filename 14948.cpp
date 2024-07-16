#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node{
    int n,m;
    int requiredLevel;
    bool isSkipped;
    Node(int n, int m, int requiredLevel, bool isSkipped):n(n),m(m),requiredLevel(requiredLevel),isSkipped(isSkipped){}
} Node;

typedef struct CMP{
    bool operator()(Node& a, Node& b){
        return a.requiredLevel != b.requiredLevel ? a.requiredLevel > b.requiredLevel : a.isSkipped > b.isSkipped;
    }
} CMP;

int N, M;
int dn[]= {0,0,-1,1};
int dm[]= {-1,1,0,0};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;

    vector<vector<int> > inputs(N,vector<int>(M,0));
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            cin >> inputs[i][j];
        }
    }

    vector<vector<bool> > isVisited(N, vector<bool>(M, 0));
    vector<vector<int> > memo(N, vector<int>(M,0));

    priority_queue<Node, vector<Node>, CMP> pq;
    pq.push(Node(0,0,inputs[0][0],0));
    isVisited[0][0] = true;

    while(!pq.empty()){
        int n = pq.top().n;
        int m = pq.top().m;
        int requiredLevel = pq.top().requiredLevel;
        pq.pop();

        isVisited[n][m] = true;

        if(n == N-1 && m == M-1){
            cout << requiredLevel;
            return 0;
        }
        bool isSkipped = pq.top().isSkipped;

        for(int i = 0 ; i < 4; i++){
            int nextN = n + dn[i];
            int nextM = m + dm[i];
            if(nextN > N -1 || nextN < 0 || nextM > M - 1 || nextM < 0){
                continue;
            }
            if(isVisited[nextN][nextM]){
                continue;
            }
            if(inputs[nextN][nextM] > requiredLevel){
                if(!isSkipped){
                    int nAfterSkipped = nextN + dn[i];
                    int mAfterSkipped = nextM + dm[i];
                    if(nAfterSkipped > N -1 || nAfterSkipped < 0 || mAfterSkipped > M - 1 || mAfterSkipped < 0){
                        continue;
                    }
                    if(isVisited[nAfterSkipped][mAfterSkipped]){
                        continue;
                    }
                    if(inputs[nAfterSkipped][mAfterSkipped] > inputs[nextN][nextM]){
                        continue;
                    }
                    int nowRequiredLevel = inputs[nAfterSkipped][mAfterSkipped] > requiredLevel ? inputs[nAfterSkipped][mAfterSkipped] : requiredLevel;
                    pq.push(Node(nAfterSkipped, mAfterSkipped, nowRequiredLevel, true));
                    
                }
                pq.push(Node(nextN, nextM, inputs[nextN][nextM], isSkipped));
            } else {
                pq.push(Node(nextN, nextM, requiredLevel, isSkipped));     
            }
        }

    }
}
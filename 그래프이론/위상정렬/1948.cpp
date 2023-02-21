//2023-02-19 19:32:40 start
//2023-02-19 21:04:46 end


#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

int n,m;

vector<pair<int,int> > edge[10001];
vector<pair<int,int> > edgeReverse[10001];
bool visited[10001]={0,};
int inDegree[10001];
int maxTime[10001]={0,};
int startNode;
int endNode;
deque<int> deq;


void solve(){
    maxTime[startNode] = 0;
    deq.push_back(startNode);
    while(!deq.empty()){
        int nodeIndex = deq.front();
        deq.pop_front();
        for(vector<pair<int, int > >::iterator iter = edge[nodeIndex].begin();iter != edge[nodeIndex].end();iter++){
            pair<int,int> currentEdge = *iter;
            if(maxTime[currentEdge.first]<maxTime[nodeIndex]+currentEdge.second){
                maxTime[currentEdge.first] = maxTime[nodeIndex]+currentEdge.second;
            }

            inDegree[currentEdge.first]--;

            if(inDegree[currentEdge.first] ==0){
                deq.push_back(currentEdge.first);
            }
        }
    }
    
}

//최대로 걸리는 시간이랑 최대로 걸리는 경로 개수
int main(){
    cin >> n >> m;

    for(int i =0 ;i < m; i++){
        register int t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        edge[t1].push_back(make_pair(t2,t3));
        edgeReverse[t2].push_back(make_pair(t1,t3));
        inDegree[t2]++;
    }
    cin >> startNode >> endNode;


    solve();

    int count = 0;

    deq.push_back(endNode);
    while(!deq.empty()){
        int node = deq.front();
        int nowTime = maxTime[node];           
        deq.pop_front();
        for(vector<pair<int, int> >::iterator iter = edgeReverse[node].begin(); iter != edgeReverse[node].end();iter++){
            int nextNode = (*iter).first;
            int time = (*iter).second;

            if(time + maxTime[nextNode] == nowTime){
                count++;
                if(visited[nextNode] == false){
                visited[nextNode] = true;
                deq.push_back(nextNode);
                }
            }
        }
    }

    cout << maxTime[endNode] << endl << count;

    return 0;
}
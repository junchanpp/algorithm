#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <set>
#include <cstring>

using namespace std;
int edge[300][300];
int inDegree[300];
int n;
priority_queue<int,vector<int> ,greater<int> > pq;
deque<int> answer;

void dfs(int startNode, int endNode){
    inDegree[startNode] = 0; // 시작지점은 모두 단방향으로 판단

    pq.push(startNode);
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();

        answer.push_back(node);

        for(int i = node+1; i <= endNode; i++){
            if(edge[node][i] == true){
                inDegree[i]--;
                if(inDegree[i]==0){
                    pq.push(i);
                }
            }
        }
    }
}

deque<int> findPath(int startNode, int endNode){
    deque<int> path;
    path.push_back(startNode);

    while (path.back() != endNode) {
        int node = path.back();

        for(int i = node+1; i <= n; i++){
            if(edge[node][i] == true){
                path.push_back(i);
                break;
            }
        }
    }

    return path;
}

deque<int> reverseConcat(deque<int>& a, deque<int>& b) {
    deque<int> result;
    for (int i = 0; i < a.size(); i++) {
        result.push_back(a[i]);
    }

    for (int i = b.size() - 2; i >= 0; i--) {
        result.push_back(b[i]);
    }

    return result;
}

int main (){
    cin >>n;

    while(1){
        int p,q;
        cin >> p >> q;
        if(p == 0 && q == 0) break;
        edge[p][q] = true;
        inDegree[q]++;
    }

    dfs(1, n);

    deque<deque<int>> pathsFrom1;
    deque<deque<int>> pathsToN;

    deque<int> curPath;
    curPath.push_back(1);
    pathsFrom1.push_back(curPath);

    curPath.clear();
    curPath.push_back(n);
    pathsToN.push_back(curPath);

    for(int i = 1 ; i < answer.size(); i++){
        int curNode = answer[i];

        deque<deque<int>> newPathsFrom1;
        for(auto path : pathsFrom1){
            if(edge[path.back()][curNode]){
                deque<int> newPath(path);
                newPath.push_back(curNode);
                newPathsFrom1.push_back(newPath);
            }
        }
        pathsFrom1.insert(pathsFrom1.end(), newPathsFrom1.begin(), newPathsFrom1.end());

        deque<deque<int>> newPathsToN;
        for(auto path : pathsToN){
            if(edge[curNode][path.front()]){
                deque<int> newPath(path);
                newPath.push_front(curNode);
                newPathsToN.push_back(newPath);
            }
        }
        pathsToN.insert(pathsToN.end(), newPathsToN.begin(), newPathsToN.end());
    }

    int longestPathLen = 0;
    deque<int> longestPath;

    for

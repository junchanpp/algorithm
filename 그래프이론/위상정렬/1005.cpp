//2022-02-22 00:25 start
//2022-02-22 02:14 end


#include<iostream>
#include<deque>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<queue>

using namespace std;
int timeTable[1001];
struct compare{
    bool operator()(int& a, int& b){
        return timeTable[a] > timeTable[b];
    }
};

int main(){
    int T;
    scanf("%d", &T) ;

    while(T--){
        int N,K;
        cin >> N >> K;
        for(int i =1; i <N+1;i++){
            scanf("%d", &timeTable[i]);
        }

        vector<int> edge[N+1];
        int inDegree[N+1];
        memset(inDegree,0,sizeof(inDegree));
        for(int i =0; i<K;i++){
            int X,Y;
            cin >> X >> Y;
            edge[X].push_back(Y);
            inDegree[Y]++;
        }
        int dest;
        scanf("%d",&dest);
        deque<int> dq;
        priority_queue<int,vector<int>, compare> pqWaitTime;
        for(int i = 1;i < N+1;i++){
            if(inDegree[i]==0){
                if(timeTable[i] == 0)dq.push_back(i);
                else pqWaitTime.push(i);
            }
        }

        int totalTime = 0;
        bool isCompleteDest = false;

        while(!dq.empty() || !pqWaitTime.empty()){
            while(!dq.empty()){
                int node = dq.front();
                dq.pop_front();
                for(int i = 0; i < edge[node].size();i++){
                    inDegree[edge[node][i]]--;
                    if(inDegree[edge[node][i]]==0){
                        if(timeTable[edge[node][i]]==0){
                            if(edge[node][i] == dest){
                                isCompleteDest = true;
                                break;
                            }
                            dq.push_back(edge[node][i]);
                        } else{
                            pqWaitTime.push(edge[node][i]);
                        }
                    }
                }
            }
            if(isCompleteDest){
                break;
            }
            if(!pqWaitTime.empty()){
                int minTime = timeTable[pqWaitTime.top()];
                totalTime+=minTime;
                vector<int> indexList;
                priority_queue<int,vector<int>, compare> newPqWaitTime;

                while(!pqWaitTime.empty()){
                    int node = pqWaitTime.top();
                    pqWaitTime.pop();
                    timeTable[node]-=minTime;
                    if(timeTable[node] ==0){
                        if(node==dest){
                            isCompleteDest = true;
                            break;
                        }
                        dq.push_back(node);
                    }else {
                        newPqWaitTime.push(node);
                    }
                }
                while(!newPqWaitTime.empty()){
                    int node = newPqWaitTime.top();
                    newPqWaitTime.pop();
                    pqWaitTime.push(node);
                }
            }

            if(isCompleteDest){
                break;
            }
        }
        printf("%d\n", totalTime);
    }
}
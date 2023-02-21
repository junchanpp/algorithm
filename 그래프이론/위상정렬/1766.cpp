//2023-02-19 18:47:38 start
//2023-02-19 18:56:40 end

#include <iostream>
#include <queue>

using namespace std;

int n,m;

vector<int> edge[32001];
int inDegree[32001]; // 자동으로 0으로 넣어져있음
priority_queue<int, vector<int>, greater<int> > pq;
queue<int> answer;


int main(){
    cin >> n >> m;

    for(int i = 0; i<m;i++){
        register int temp1, temp2;
        cin >> temp1 >> temp2;

        edge[temp1].push_back(temp2);
        inDegree[temp2]++;
    }

    for(int i = 1; i<=n;i++){
        if(inDegree[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int value = pq.top();
        pq.pop();
        answer.push(value);

        for(vector<int>::iterator iter = edge[value].begin(); iter < edge[value].end();iter++){
            inDegree[*iter]--;
            if(inDegree[*iter]==0){
                pq.push(*iter);
            }
        }
    }

    while(!answer.empty()){
        cout << answer.front() << " ";
        answer.pop();
    }
}
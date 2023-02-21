//2023-02-20 01:28:00 start


#include<iostream>
#include<vector>
#include<deque>
#include<string.h>
#include<stack>
#include <algorithm>

using namespace std;

int n;
vector<int>v[300];//커지는 경로밖에 없음
vector<int>vReverse[300];// 작아지는 경로밖에 없음
int distanceFor1[300];// 처음 1과의 거리
stack<int>answer1;

bool isAfterN = false;

int maxCount = 0;
vector<int>answer;

deque<int> deq;

bool dfs(int node,int count, deque<int> dq){
    bool isGetN = false;
    if(node == 1 && count !=1){
        if(count > maxCount){
            deq.clear();
            maxCount = count;
            for(int i =0; i< dq.size();i++){
                deq.push_back(dq[i]);
            }
        }

        return true;
    }
    if(isAfterN){
        for(vector<int>::iterator iter = vReverse[node].begin(); iter != vReverse[node].end(); iter++){
            int currentNode = *iter;

            dq.push_front(currentNode);
            bool result = dfs(currentNode,count+1,dq);
            dq.pop_front();
            if(result == false ){
            }else {
                isGetN = true;
            }
        }
    }
    else {
        for(vector<int>::iterator iter = v[node].begin(); iter != v[node].end(); iter++){
            int currentNode = *iter;

            if(currentNode == n){
                isAfterN = true;
            }

            vector<int> backupvReverse = vector<int>();
            for(int i = 0; i < vReverse[currentNode].size();i++){
                if(vReverse[currentNode][i]!= node)backupvReverse.push_back(vReverse[currentNode][i]);
            }
            swap(backupvReverse, vReverse[currentNode]);
            dq.push_front(currentNode);
            bool result = dfs(currentNode,count+1,dq);
            dq.pop_front();
            swap(backupvReverse, vReverse[currentNode]);
            if(currentNode == n){isAfterN = false;}
            if(result == false ){
            } else {
                isGetN = true;
            }
        }
    }
    return isGetN;
}

int main(){z
    cin >> n;

    int p,q;
    while(1){
        cin >> p >> q;

        if(p==0&&q==0)break;

        v[p].push_back(q);
        vReverse[q].push_back(p);
    }

    distanceFor1[1] = 1;
    deque<int> dq;
    dq.push_front(1);
    dfs(1,distanceFor1[1],dq);

    cout << maxCount << endl;

    while(!deq.empty()){
        cout << deq.front() << " " ;
        deq.pop_front();
    }


}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

int N,K;


int main(){
    cin >> N >> K;
    vector<pair<int, int> > J;
    vector<int> C;
    for(int i = 0; i<N;i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        J.push_back(make_pair(temp1,temp2));
    }

    for(int i = 0; i<K;i++){
        int temp1;
        cin >> temp1;
        C.push_back(temp1);
    }

    sort(J.begin(),J.end());
    sort(C.begin(),C.end());

    long long sum = 0;
    int jIndex = 0;
    priority_queue<int> pq;
    for(int i = 0 ; i < K; i++){
        while(jIndex < N && J[jIndex].first <= C[i]){
            pq.push(J[jIndex++].second);
        }
        if(!pq.empty()){
            sum+=(long long)pq.top();
            pq.pop();
        }
    }
    cout << sum;
}
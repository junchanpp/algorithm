#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;



int main(){
    int N;
    cin >> N;
    queue<int> q;
    bool arr[N+1];
    fill(arr,arr+(N+1),false);

    for(int i =2; i <= N;i++){
        if(arr[i])continue;
        q.push(i);
        for(int j=i*2; j <=N;j+=i){
            arr[j]=true;
        }
    }
    int sum = 0;
    deque<int> dq;
    int count = 0;
    while(!q.empty()){
        while(sum<N){
            int value = q.front();
            q.pop();
            dq.push_back(value);
            sum+=value;
        }
        if(sum==N){
            count++;

            int value = dq.front();
            dq.pop_front();
            sum-=value;
        }
        else {
            while(sum>N){
                int value = dq.front();
                dq.pop_front();
                sum-=value;
            }
            if(sum==N){
                count++;
                int value = dq.front();
                dq.pop_front();
                sum-=value;
            }
        }
    }

    cout << count;
}
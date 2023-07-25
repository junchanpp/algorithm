#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int K;
        cin >>K;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(int i = 0; i< K;i++){
            int temp;
            cin >> temp;
            pq.push(temp);
        }
        long long sum = 0;
        while(pq.size()!=1){
            long long value1 = pq.top();pq.pop();
            long long value2 = pq.top();pq.pop();
            sum+=value1+value2;
            pq.push(value1+value2);
        }
        cout << sum << endl;
    }

    
}
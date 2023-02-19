

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>


using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;

    pair<int, int> arr[n];

    for(int i=0;i<n;i++){
        int temp;
        int start,end;
        cin >> temp >> start >> end;
        arr[i] = make_pair(start,end);
    }

    sort(arr, arr+n,compare);
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(0);
    for(int i = 0; i < n; i++){
        if(pq.top() <= arr[i].first){
            pq.push(arr[i].second);
            pq.pop();
        }else {
            pq.push(arr[i].second);
        }
    }

    cout << pq.size();

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }
    cin >> K;
    vector<pair<bool, int> > op;
    for(int i = 0 ; i < 2* K; i++){
        pair<bool, int> cur;
        cur.first = i % 2 == 0; //1이 오름차순
        cin >> cur.second;
        cur.second--;

        while(!op.empty() && cur.second >= op.back().second){
            op.pop_back();
        }
        if(op.empty() || op.back().first != cur.first){
            op.push_back(cur);
        }
    }
    deque<int> dq;
    copy(arr.begin(), arr.begin() + op[0].second + 1, back_inserter(dq));
    sort(dq.begin(), dq.end());

    for(int i = 0; i < op.size(); i++){
        bool isAsc = op[i].first;
        int start = i == op.size()-1 ? 0 : op[i+1].second + 1;
        int end = op[i].second;
        
        for(int j = start; j <= end; j++){
            if(isAsc){
                arr[end- j + start] = dq.back();
                dq.pop_back();
            } else {
                arr[end- j + start] = dq.front();
                dq.pop_front();
            }
        }
    }

    for(int i = 0 ; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}
#include <iostream>
#include <deque>
#include <utility>
#include <vector>

using namespace std;

deque<pair<int, int> > dq;
vector<int> D;
int N, L;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> L;
    D.assign(N,0);
    for(int i = 0 ; i < N; i++){
        int input;
        cin >> input;
        
        
        while(dq.size() && dq.back().first >= input){
            dq.pop_back();
        }
        dq.push_back(make_pair(input, i));
        while(dq.front().second < i - L + 1){
            dq.pop_front();
        }
        D[i] = dq.front().first;
    }
    for(int i = 0; i < N; i++){
        cout << D[i] << " ";
    }
}
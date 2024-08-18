#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int, int> > pq;
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
        pq.push(make_pair(input * -1, i));
        while(pq.top().second < i - L + 1){
            pq.pop();
        }
        D[i] = pq.top().first * -1;
    }
    for(int i = 0; i < N; i++){
        cout << D[i] << " ";
    }
}
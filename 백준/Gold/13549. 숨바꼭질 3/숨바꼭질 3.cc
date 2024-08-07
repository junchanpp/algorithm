#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

vector<int> visited;
int N, K;

int main(){
    cin >> N >> K;
    priority_queue<pair<int, int> > pq;
    visited.assign(max(2*(N+1),2*(K+1)), INT_MAX);
    pq.push(make_pair(0,N));
    visited[N] = 0;
    while(pq.top().second != K){
        int count = pq.top().first * -1;
        int x = pq.top().second;
        pq.pop();
        if(count > visited[x]){
            continue;
        }
        if(x*2 < visited.size() && x > 0 && visited[x*2] > count){
            visited[x*2] = count;
            pq.push(make_pair(count * -1, x*2));
        }
        if(x+1 < visited.size() && visited[x+1] > count + 1){
            visited[x+1] = count +1;
            pq.push(make_pair((count+1) * -1, x+1));
        }
        if(x-1 >= 0 && visited[x-1] > count + 1){
            visited[x-1] = count +1;
            pq.push(make_pair((count+1) * -1, x-1));
        }
    }

    cout << pq.top().first * -1;
}
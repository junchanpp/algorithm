#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<bool> visited;
int N;

int main(){
    cin >> N;
    visited.assign(N+1, 0);

    priority_queue<pair<int, int> > pq;//그냥 q여도 상관 x

    pq.push(make_pair(0, N));
    while(pq.top().second != 1){
        int count = pq.top().first * -1;
        int num = pq.top().second;
        pq.pop();
        if(num % 3 == 0 && !visited[num/3]){
            visited[num/3] = 1;
            pq.push(make_pair((count+1) * -1, num/3));
        }
        if(num % 2 == 0 && !visited[num/2]){
            visited[num/2] = 1;
            pq.push(make_pair((count+1) * -1, num/2));
        }
        if(!visited[num-1]){
            visited[num-1] = 1;
            pq.push(make_pair((count+1) * -1, num-1));
        }
    }
    cout << pq.top().first * -1;


}
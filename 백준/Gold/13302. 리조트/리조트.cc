#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int N, M;
vector<int> inputs;
priority_queue<pair<int, pair<int, int> > > pq;//비용, 쿠폰 개수, 현재 일수
vector<vector<int> > visited;//현재 일수



int answer = 0;

void insertPq(int cost, int coupon, int date){
    while(date <= N && inputs[date]){
        date++;
    }
    if(date <= N){
        if(visited[date][coupon] <= cost){
            return;
        }
        visited[date][coupon] = cost;
    }
    pq.push(make_pair(-1 * cost, make_pair(coupon, date)));
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    inputs.assign(N+1, 0);
    visited.assign(N+1, vector<int>(50, INT_MAX));
    for(int i = 0; i < M; i++){
        int t;
        cin >> t;
        inputs[t] = 1;
    }

    int result = INT_MAX;
    insertPq(0,0,1);

    

    while(!pq.empty()){
        int cost = pq.top().first * -1;
        int coupon = pq.top().second.first;
        int date = pq.top().second.second;
        pq.pop();

        if(date > N){
            if(result > cost){
                result = cost;
            }
            continue;
        }
        if(visited[date][coupon] < cost){
            continue;
        }
        
        if(coupon >= 3){
            insertPq(cost, coupon-3, date+1);
        }

        insertPq(cost+10000, coupon, date+1);
        insertPq(cost+25000, coupon+1, date+3);
        insertPq(cost+37000, coupon+2, date+5);
    }




    cout << result;
}
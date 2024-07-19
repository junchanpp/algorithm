#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;

long long N, M, C;//N은 최대 10만, M은 최대 20만, C는 최대 10만

vector<vector<pair<int, long long> > > edges;
vector<long long> costs;



//1. 광장 1로부터 모든 광장의 최소거리 <- 우선순위큐를 이용한 다익스트라로 해결
//2. D = 10,000 거리 별로 광장의 개수 저장
//3. X를 늘려가며 최소 비용 찾기

int main(){
    cin >> N >> M >> C;//광장 N개, 도로 M개, 지하도 설치 변수 C

    edges.assign(N+1,vector<pair<int, long long> >(0));
    costs.assign(N+1,LLONG_MAX);

    costs[1] = 0;
    

    long long totalCost = 0;
    //입력 처리
    for(int i = 0 ; i < M; i++){
        long A, B, D;
        cin >> A >> B >> D;
        if(A > B){
            long temp = A;
            A = B;
            B = temp;
        }
        edges[A].push_back(make_pair(B, D));
        edges[B].push_back(make_pair(A, D));

        totalCost += D;
    }
    
    //1번 항목 처리
    priority_queue<pair<long long, int> > pq;//first: cost, second.first: 도시 번호, second.second: 거쳐온 도시의 정보

    pq.push(make_pair(0,1));

    long long answer = totalCost;

    while(!pq.empty()){
        long long cost = pq.top().first * -1;
        int index = pq.top().second;
        pq.pop();

        if(cost > costs[index]){
            continue;
        }
        for(int i = 0; i < edges[index].size(); i++){
            int nextIndex = edges[index][i].first;
            long long nextTempCost = edges[index][i].second;

            if(costs[nextIndex] < costs[index] || (costs[nextIndex] == costs[index] && nextIndex > index)){
                totalCost -= nextTempCost;
            }
        }

        answer = min(answer, costs[index] * C + totalCost);


        for(int i = 0; i < edges[index].size(); i++){
            int nextIndex = edges[index][i].first;
            long long nextCost = edges[index][i].second + cost;
            

            if(costs[nextIndex] > nextCost){
                costs[nextIndex] = nextCost;
                pq.push(make_pair(nextCost * -1, nextIndex));
            }
        }
    }
    cout << answer;
}
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

int N, M, K;
int S, D;
int extraFee = 0;
vector<vector<pair<int, int> > > arr;//index: 시작지점. first: 도착지점. second 기본 비용.
vector<vector<int> > memo;

void solve();

int getAnswer();

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;

    cin >> S >> D;

    arr.assign(N+1, vector<pair<int,int> >(0));

    for(int i = 0 ; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        arr[start].push_back(make_pair(end,cost));
        arr[end].push_back(make_pair(start,cost));
    }

    vector<int> answers;
    
    solve();

    answers.push_back(getAnswer());
    

    for(int i = 0; i < K; i++){
        int fee = 0;
        cin >> fee;
        extraFee += fee;
        answers.push_back(getAnswer());
    }


    for(int i = 0; i < answers.size(); i++){
        cout << answers[i] << endl;
    }
}

typedef struct cmp{
    bool operator()(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        return a.second > b.second;
    }
}cmp;

void solve(){
    memo.assign(N+1, vector<int>(N+1,INT_MAX));
    priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int> ,int> >, cmp > pq;
    pq.push(make_pair(make_pair(S,0),0));
    for(int i = 0 ; i < N; i++){
        memo[S][i] = 0;
    }

    while(!pq.empty()){
        int start = pq.top().first.first;
        int count = pq.top().first.second;
        int cost = pq.top().second;

        pq.pop();

        if(memo[start][count] != cost){
            continue;
        }

        for(int i = 0; i < arr[start].size(); i++){
            int end = arr[start][i].first;
            int nextCount = count + 1;
            int nextCost = arr[start][i].second + cost;
            if(memo[end][nextCount] > nextCost){
                for(int i = nextCount; i < N;i++){
                    if(memo[end][i] <= nextCost){
                        break;
                    }
                    memo[end][i] = nextCost;
                }
                pq.push(make_pair(make_pair(end, nextCount), nextCost));
            }
        }
    }
}

int getAnswer(){
    int minValue = INT_MAX;
    for(int i = 0 ; i < N; i++){
        if(memo[D][i] != INT_MAX && minValue > memo[D][i] + extraFee * i){
            minValue = memo[D][i] + extraFee * i;
        }
    }

    return minValue;
}
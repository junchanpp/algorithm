#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

long long N, D;
vector<long long> inputs;
deque<pair<long long, long long> > dq;
vector<long long> dp;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> D;
    inputs.assign(N,0);
    dp.assign(N,0);
    for(int i = 0; i < N; i++){
        cin >> inputs[i];
        while(dq.size() && dq.front().second < i - D){
            dq.pop_front();
        }
        dp[i] = max(inputs[i], (dq.empty() ? 0 : dq.front().first) + inputs[i]);

        while(dq.size() && dq.back().first <= dp[i]){
            dq.pop_back();
        }
        dq.push_back(make_pair(dp[i], i));
    }

    long long answer = LLONG_MIN;
    for(int i = 0 ; i < N; i++){
        answer = max(answer, dp[i]);
    }
    cout << answer;
}
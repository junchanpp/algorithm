#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N,M,K;
vector<pair<int, int> > score;

struct  cmpFirst{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.first < b.first;       
    }
} cmpFirst;
struct  cmpSecond{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }
} cmpSecond;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long sum = 0;

    cin >> N >> M >> K;

    for(int i = 0 ; i < N; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        score.push_back(make_pair(temp1, temp2));
    }

    sort(score.begin(), score.end(), cmpSecond);

    for(int i = 0 ; i < K;i++){
        sum += score.back().first;
        score.back().first = -100;
        score.pop_back();
    }
    
    sort(score.begin(), score.end(), cmpFirst);
    for(int i = 0; i < M; i++){
        sum += score.back().first;
        score.pop_back();
    }

    cout << sum << endl;

}



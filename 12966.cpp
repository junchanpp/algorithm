#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(pair<long long, int> a, pair<long long, int> b){
        return a.second > b.second;
    }
};

long long sumOdd(int n){
    return n*n;
}

long long x,y;
int main(){
    cin >> x >> y;
    
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, cmp > q;// 현재까지 윤호의 점수, 이긴 횟수
    q.push(make_pair(0,0));

    int i = 0;


    while(!q.empty()){
        int queueSize = q.size();
        for(int a = 0; a < queueSize; a++){
            int nowScore = q.top().first;
            int opponentScore = sumOdd(i) - nowScore;
            int winCount = q.top().second;
            q.pop();
            if(nowScore == x && opponentScore == y){
                cout << winCount;
                return 0;
            }
                cout << "a: " << nowScore << " " << (2*i+1) << " "  << x << endl;
            if(nowScore + (2*i+1) <= x){
                cout << "b: " << nowScore << " " << (2*i+1) << " "  << x << endl;
                q.push(make_pair(nowScore+(2*i+1), winCount+1));
            }
            if(opponentScore + (2*i+1) <= y){
                q.push(make_pair(nowScore, winCount));
            }
        }
        i++;
    }

    cout << -1;
}
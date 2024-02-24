#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
int D;
vector<long long> monkey;
vector<long long> str;
vector<pair<double, pair<int, int> > > dStr;// first는 second-1에서 second로 레벨업할 때 힘 변화량, 그때 인덱스 second

long long calculateMonkey(){
    long long sum = 0;
    for(int i = 0 ; i < N ;i++){
        sum+= (long long)monkey[i]*str[i];
    }
    return sum;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    monkey.resize(N+1);
    str.resize(N+1);
    for(int i = 0 ; i < N ; i++){
        cin >> monkey[i];
    }
    for(int i = 0 ; i < N ; i++){
        cin >> str[i];
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = i+1; j < N; j++){
            int from = i;
            int to = j;
            double d = (str[j] - str[i])/(to-from);
            dStr.push_back(make_pair(d, make_pair(from,to)));
        }
    }
    cin >> D;

    sort(dStr.begin(), dStr.end());

    while(D>0){
        int nowD = D;
        int i = dStr.size()-1;
        while(nowD == D && i >= 0){
            pair<double, pair<int, int> > nextLevelInfo = dStr[i];
            pair<int, int> toFromIndex = nextLevelInfo.second;
            if(nextLevelInfo.first <= 0){
                D = 0;
                break;
            }
            int from = toFromIndex.first;
            int to = toFromIndex.second;
            if(monkey[from] <= 0  || D < to - from){
                i--;
                continue;
            }
            monkey[from]--;
            monkey[to]++;
            D-= (to-from);
        }
        if(nowD == D && i < 0){
            D--;
        }
    }

    cout << calculateMonkey();

    return 0;

}
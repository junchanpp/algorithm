#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;


bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first < b.first;
}
bool comp2(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first > b.first;
}

int main(){
    int N;
    cin >> N;
    vector<pair<long long,long long> > score(N);
    vector<pair<long long,long long> > scoreB(N);
    bool isUsed[N];
    for(int i = 0 ; i < N; i++){
        cin >> score[i].first;
        scoreB[i].second = score[i].first;
        isUsed[i] = false;
    }
    for(int i = 0 ; i < N; i++){
        cin >> score[i].second;
        scoreB[i].first = score[i].second;
    }

    sort(score.begin(),score.end(),greater<pair<long long,long long> >());
    sort(scoreB.begin(),scoreB.end());

    long long sumValue = 0;
    int garbageCount = 0;

    for(int i = 0; i < N;i++){
        if(isUsed[i])continue;
        if(garbageCount >0){
            garbageCount--;
            sumValue+=(score[i]).first;
            continue;
        }
        
        int h = upper_bound(scoreB.begin(),scoreB.end(),pair<int,int>(score[i].second,0),comp)- scoreB.begin();
        int index;
        if(h == N)index = i;
        else {
            index = lower_bound(score.begin(),score.end(),pair<int,int>(scoreB[h].second,0),comp2)-score.begin();
            while( (h < N && index < N && isUsed[index])){
                h++;
                index = lower_bound(score.begin(),score.end(),pair<int,int>(scoreB[h].second,0),comp2)-score.begin();
            }
        }
        if(index < i || h ==N || index == N)index = i;
        
        isUsed[i] = true;
        isUsed[index]= true;
        if(index != i && index != N){
            sumValue+=(score[i]).first;
        } else {
            garbageCount++;
        }
    }
    cout << sumValue;
}
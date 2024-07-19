#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef struct cmp_lo{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        return a.first != b.first ? a.first > b. first : a.second > b.second;
    }
}cmp_lo;

typedef struct cmp_hi{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        return a.second != b.second ? a.second > b. second : a.first > b.first;
    }
}cmp_hi;

int N, length;
vector<pair<int,int> > points;
priority_queue<pair<int,int>, vector<pair<int,int> >, cmp_lo> pq_lo;//lo가 작은 순
priority_queue<pair<int,int>, vector<pair<int,int> >, cmp_hi> pq_hi;//hi가 작은 순

using namespace std;

int solve();


/**
 * 실패
 */
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i = 0 ; i < N;i++){
        pair<int,int> point;
        cin >> point.first >> point.second;
        if(point.first > point.second){
            int temp;
            temp =point.first;
            point.first = point.second;
            point.second = temp;
        }
        points.push_back(point);
    }
    cin >> length;

    for(int i = 0 ; i < points.size();i++){
        if(points[i].second - points[i].first <= length){
            pq_lo.push(points[i]);
            pq_hi.push(points[i]);
        }
    }

    cout << solve();

    return 0;

}

int solve(){
    int maxCount = 0;

    deque<pair<int,int> > dq_lo;
    deque<pair<int,int> > dq_hi;

    while(!pq_lo.empty()){
        dq_lo.push_back(pq_lo.top());
        pq_lo.pop();
    }

    while(!pq_hi.empty()){
        dq_hi.push_back(pq_hi.top());
        pq_hi.pop();
    }

    while(dq_lo.size() > maxCount && dq_hi.size() > maxCount){
        int currentStart = dq_lo.front().first;
        dq_lo.pop_front();

        while(!dq_hi.empty() && (dq_hi.front().first < currentStart)){dq_hi.pop_front();}

        int count = 0;
        for(auto iter = dq_hi.begin(); iter != dq_hi.end(); iter++){
            pair<int,int> nowPoint = *iter;
            if(nowPoint.second - currentStart > length){//hi가 벗어나면 break;
                break;
            }
            if(nowPoint.first >= currentStart){//lo가 벗어나면 지켜보기
                count++;
            }
        }
        if(maxCount < count){
            maxCount = count;
        }

    }

    return maxCount;
}
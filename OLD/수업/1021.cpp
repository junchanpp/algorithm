#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n, cur;
vector<pair<int,int> > v;

typedef struct Calc//계산하기 위해 구조체 선언
{
    int cost;//현재까지 소모된 비용
    int left;//이미 스캔한 최소 left
    int right;//이미 스캔한 최대 right
    int nowCur;//현재 위치
    int time;//흐른 시간
    Calc(int cost,int left,int right, int nowCur, int time):cost(cost),left(left),right(right),nowCur(nowCur),time(time){}
} Calc;
struct compare{
    bool operator()(const Calc& c1, const Calc& c2){
        return c1.cost > c2.cost;//비용기준 오름차순 정렬
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> cur;
    cur--;
    for(int i = 0 ; i < n ; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1,temp2));//입력을 알맞게 변환
    }

    priority_queue<Calc, vector<Calc>, compare> pq;
    pq.push(Calc(0,cur,cur,cur,0));

    while(pq.top().left != 0 ||pq.top().right != n-1){//모든 범위를 스캔할때까지 계속 진행. 우선순위 큐이므로, 최소비용 보장
        Calc nowCalc = pq.top();
        int left = nowCalc.left;
        int right = nowCalc.right;
        int cost = nowCalc.cost;
        int nowCur = nowCalc.nowCur;
        int time = nowCalc.time;
        pq.pop();

        //왼쪽으로 한칸 움직여 비용 계산하여 우선순위 큐에 삽입
        if(left > 0)pq.push(Calc(cost+(time+v[nowCur].first-v[left-1].first)*v[left-1].second,left-1,right,left-1, time+v[nowCur].first-v[left-1].first));
        
        //오른쪽으로 한칸 움직여 비용 계산하여 우선순위 큐에 삽입
        if(right < n-1)pq.push(Calc(cost+(time+v[right+1].first-v[nowCur].first)*v[right+1].second,left,right+1,right+1, time+v[right+1].first-v[nowCur].first));
    }
    int answer = pq.top().cost;

    cout << answer << endl;
}
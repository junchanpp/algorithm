#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define INF 150001 

int N,M;
int maze[101][101];
int cost[101][101];
int dyList[] = {1,-1,0,0};
int dxList[] = {0,0,1,-1};

struct compare{
    bool operator()(pair<int,pair<int,int> >& point1, pair<int,pair<int,int> >& point2){
        if(point1.first == point2.first){
            if(point1.second.first ==point2.second.first){
                return point1.second.second > point2.second.second;
            }
            return point1.second.first > point2.second.first;
        }
        return point1.first > point2.first;
    }
};

int main(){
    cin >> M >> N;//N세로, M 가로
    fill(&cost[0][0],&cost[0][0]+101*101,INF);

    for(int i = 0; i< N;i++){
        string s;
        cin >> s;
        for(int j = 0; j < M;j++){
            maze[i][j] = (s[j] == '1');
        }
    }

    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, compare> pq;

    cost[0][0] = 0;
    pq.push(make_pair(0,make_pair(0,0)));

    while(!pq.empty()){
        int distance = pq.top().first;
        pair<int,int> point = pq.top().second;
        pq.pop();

        if(cost[point.second][point.first] < distance)continue;
        for(int i = 0; i< 4; i++){
            int dy = dyList[i];
            int dx = dxList[i];
            if(point.first+dx < 0 || point.first+dx >= M || point.second+dy < 0 || point.second+dy >= N)continue;
            if(cost[point.second+dy][point.first+dx] > distance+maze[point.second+dy][point.first+dx]){
                cost[point.second+dy][point.first+dx] = distance+maze[point.second+dy][point.first+dx];
                pq.push(make_pair(cost[point.second+dy][point.first+dx], make_pair(point.first+dx, point.second+dy)));
            }
        }
    }

    cout << cost[N-1][M-1];
}
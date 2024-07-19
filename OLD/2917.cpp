#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

vector<vector<int> > riskMap;
vector<vector<int> > treeMap;
int N, M;
int startY, startX;
int endY, endX;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void spreadRisk(int y, int x){
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    int cost = 1;
    while(!q.empty()){    
        int size = q.size();
        for(int i = 0 ; i < size; i++){

            int currentY = q.front().first;
            int currentX = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nextY = currentY+dy[i];
                int nextX = currentX+dx[i];

                if(nextY >= N || nextX >= M || nextY < 0 || nextX < 0){
                    continue;
                }
                if(riskMap[nextY][nextX] <= cost){
                    continue;
                }

                riskMap[nextY][nextX] = cost;
                q.push(make_pair(nextY,nextX));
            }
        }
        cost++;
    }
}

int main(){
    cin >> N >> M;
    treeMap.assign(N,vector<int>(M));// 1이면 나무가 있는 자리
    riskMap.assign(N,vector<int>(M,INT_MAX));

    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            if(s[j] == 'V'){
                startY = i;
                startX = j;
            }else if(s[j] =='J'){
                endY = i;
                endX = j;
            }else if(s[j] == '+'){
                riskMap[i][j] = 0;
            }
            treeMap[i][j] = (s[j] == '+' ? 1 : 0);
        }
    }

    //riskMap에서 0이 발견되면 사방으로 1씩 더해서 퍼져나가기
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j< M; j++){
            if(riskMap[i][j] == 0){
                spreadRisk(i,j);
            }
        }
    }


    //길찾기
    priority_queue<pair<int, pair<int,int> > > pq;
    vector<vector<bool> > isVisited(N, vector<bool>(M,0));
    pq.push(make_pair(riskMap[startY][startX],make_pair(startY, startX)));

    while(!pq.empty()){
        int cost = pq.top().first;
        int y = pq.top().second.first;
        int x= pq.top().second.second;
        pq.pop();

        if(y == endY && x == endX){
            cout << cost;
            return 0;
        }

        for(int i = 0 ; i < 4; i++){
            int nextY = y+dy[i];
            int nextX = x+dx[i];
            
            if(nextY >= N || nextX >= M || nextY < 0 || nextX < 0){
                continue;
            }
            if(isVisited[nextY][nextX]){
                continue;
            }
            int nextCost = min(cost, riskMap[nextY][nextX]);
            
            isVisited[nextY][nextX]= 1;
            pq.push(make_pair(nextCost,make_pair(nextY, nextX)));
        }
    }


}
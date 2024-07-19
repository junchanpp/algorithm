#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N,M,K;
vector<vector<int> > inputs;


int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

long long countArea(int y, int x){
    long long count = 0;
    queue<pair<int,int> >q;

    q.push(make_pair(y,x));
    inputs[y][x] = true;

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        count++;

        for(int i = 0 ; i < 4; i++){
            int nextY = curY+dy[i];
            int nextX = curX+dx[i];

            if(nextY >=N || nextX >= N || nextY < 0 || nextX < 0){
                continue;
            }
            if(inputs[nextY][nextX]){
                continue;
            }
            inputs[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
        }
    }

    return count;
}

int main(){
    
    cin >> N >> M >> K;

    inputs.assign(N, vector<int>(N,0));

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> inputs[i][j];
        }
    }
    

    vector<long long> areas;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(inputs[i][j]){
                continue;
            }
            areas.push_back(countArea(i, j));
        }
    }

    int leftM = M;

    for(int i = 0; i < areas.size();i++){
        leftM -= areas[i]/K + (areas[i]%K == 0 ? 0 : 1);
        if(leftM < 0){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    if(leftM == M){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE\n" << leftM;
    }

    
        return 0;
}
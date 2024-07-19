#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

int dy[] = {1,1,2,2,-1,-1,-2,-2};
int dx[] = {2,-2,1,-1,2,-2,1,-1};

int main(){
    int N, x, y, K;
    cin >> N >> y >> x >> K;

    queue<pair<int, int> > q;
    q.push(make_pair(y,x));

    int k = 0;
    int outPercentage = 0;
    vector<vector<double> > memo(N+1, vector<double>(N+1, 0));
    memo[y][x] = 1;
    while(!q.empty()){
        if(k == K){
            break;
        }
        vector<vector<double> > prevMemo(memo);
        memo.assign(N+1, vector<double>(N+1, 0));

        int size = q.size();
        for(int i = 0 ; i < size; i++){
            int curY = q.front().first;
            int curX = q.front().second;
            double percentage = prevMemo[curY][curX];
            q.pop();
            for(int j = 0; j < 8; j++){
                int nextY = curY + dy[j];
                int nextX = curX + dx[j];
                if(nextY > N || nextX > N || nextY < 1 || nextX < 1){
                    continue;
                }
                if(memo[nextY][nextX] == 0){
                    q.push(make_pair(nextY, nextX));
                }
                memo[nextY][nextX]+=percentage/8;
            }
        }
        k++;
    }

    double inPercentage = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <=N;j++){
            inPercentage+= memo[i][j];
        }
    }
    cout << fixed << setprecision(20)<<  inPercentage << endl;
}
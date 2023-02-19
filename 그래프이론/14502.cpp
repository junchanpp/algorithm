//2023-02-17 17:32:30 start
//2023-02-17 18:17:21 end

#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
int dfs(int cnt,int map[9][9]);
int bfs(int map[9][9]);
deque<pair<int,int> > virous;
int main() {
    int map[9][9];
    cin >> n >> m;// n이 세로, m이 가로
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j]==2){
                virous.push_back(make_pair(i,j));
            }
        }
    }
    int max = dfs(0,map);

    cout << max << endl;
}

int dfs(int cnt,int map[9][9]){
    if(cnt == 3){
        int result = bfs(map);
        return result;
    }
    int max = 0;

    for(int i =0;i < n;i++){
        for(int j =0;j<m;j++){
            if(map[i][j] ==0){
                map[i][j]=1;
                int temp = dfs(cnt+1,map);
                if(temp > max)max = temp;
                map[i][j]=0;
            }
        }
    }
    return max;
}
int dyList[]={1,-1,0,0};
int dxList[]={0,0,1,-1};

int bfs(int sourceMap[9][9]){
    int map[9][9];
    copy(&sourceMap[0][0],&sourceMap[0][0]+9*9, &map[0][0]);
    deque<pair<int,int> > v(virous);

    while(!v.empty()){
        pair<int,int> point = v.front();
        v.pop_front();

        for(int i = 0; i< 4;i++){
            int y = dyList[i]+point.first;
            int x = dxList[i]+point.second;
            if(y < 0 || y >= n || x < 0 || x >= m)continue;
            if(map[y][x] == 0){
                map[y][x] = 2;
                v.push_back(make_pair(y,x));
            }
        }
    }
    int count = 0;
    for(int i =0 ;i<n;i++){
        for(int j = 0; j<m;j++){
            if(map[i][j]==0)count++;
        }
    }
    return count;
}
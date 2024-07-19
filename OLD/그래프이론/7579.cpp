//2023-02-16 23:12:53 start
//2023-02-16 23:37:18 end

#include <iostream>
#include <queue>
#include <utility>

using namespace std;


int arr[101][101][101];
int m,n,h;
int checkAll(void);

struct POINT{
    int first;
    int second;
    int third;

};

POINT make_point(int first, int second, int third){
    POINT point = {first,second,third};
    return point;
}
int main () {

    cin >> m >> n >> h;

    queue<POINT> nowCompleteQueue;

    for(int k = 0;k<h;k++){
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                int temp;
                cin >> temp;
                arr[i][j][k] = temp;

                if(temp == 1)nowCompleteQueue.push(make_point(i,j,k));
            }
        }
    }

    while(!nowCompleteQueue.empty()){
        POINT nowPoint = nowCompleteQueue.front();
        nowCompleteQueue.pop();

        if(nowPoint.first > 0 && arr[nowPoint.first-1][nowPoint.second][nowPoint.third] == 0){
            nowCompleteQueue.push(make_point(nowPoint.first-1, nowPoint.second, nowPoint.third));
            arr[nowPoint.first-1][nowPoint.second][nowPoint.third] = arr[nowPoint.first][nowPoint.second][nowPoint.third]+1;
        }
        if(nowPoint.first < n-1 && arr[nowPoint.first+1][nowPoint.second][nowPoint.third] == 0){
            nowCompleteQueue.push(make_point(nowPoint.first+1, nowPoint.second, nowPoint.third));
            arr[nowPoint.first+1][nowPoint.second][nowPoint.third] = arr[nowPoint.first][nowPoint.second][nowPoint.third]+1;
        }
        if(nowPoint.second > 0 && arr[nowPoint.first][nowPoint.second-1][nowPoint.third] == 0){
            nowCompleteQueue.push(make_point(nowPoint.first, nowPoint.second-1, nowPoint.third));
            arr[nowPoint.first][nowPoint.second-1][nowPoint.third] = arr[nowPoint.first][nowPoint.second][nowPoint.third]+1;
        }
        if(nowPoint.second < m-1 && arr[nowPoint.first][nowPoint.second+1][nowPoint.third] == 0){
            nowCompleteQueue.push(make_point(nowPoint.first, nowPoint.second+1,nowPoint.third));
            arr[nowPoint.first][nowPoint.second+1][nowPoint.third] = arr[nowPoint.first][nowPoint.second][nowPoint.third]+1;
        }
        if(nowPoint.third > 0 && arr[nowPoint.first][nowPoint.second][nowPoint.third-1] == 0){
            nowCompleteQueue.push(make_point(nowPoint.first, nowPoint.second, nowPoint.third -1));
            arr[nowPoint.first][nowPoint.second][nowPoint.third-1] = arr[nowPoint.first][nowPoint.second][nowPoint.third]+1;
        }
        if(nowPoint.third < h-1 && arr[nowPoint.first][nowPoint.second][nowPoint.third+1] == 0){
            nowCompleteQueue.push(make_point(nowPoint.first, nowPoint.second, nowPoint.third +1));
            arr[nowPoint.first][nowPoint.second][nowPoint.third+1] = arr[nowPoint.first][nowPoint.second][nowPoint.third]+1;
        }
    }
    int result = checkAll();

    cout << result;

    return 0;
}

//다 익었으면 true, 하나라도 안익었으면 false
int checkAll(){
    int max = 0;
    for(int i = 0; i< n; i++){
        for(int j = 0;j<m;j++){
            for(int k = 0; k < h; k++){
              if(arr[i][j][k] == 0)return -1;
              else if(max <= arr[i][j][k]) max = arr[i][j][k];
            }
        }
    }
    return max -1;
}
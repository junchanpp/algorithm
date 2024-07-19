//2023-02-16 22:04:53 start
//2023-02-16 23:07:00 end

#include <iostream>
#include <queue>
#include <utility>

using namespace std;


int arr[1001][1001];
int m,n;
int checkAll(void);


int main () {

    cin >> m >> n;

    queue< pair<int,int> > nowCompleteQueue;

    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            int temp;
            cin >> temp;
            arr[i][j] = temp;

            if(temp == 1)nowCompleteQueue.push(make_pair(i,j));
        }
    }

    while(!nowCompleteQueue.empty()){
        pair<int,int> nowPoint = nowCompleteQueue.front();
        nowCompleteQueue.pop();

        if(nowPoint.first > 0 && arr[nowPoint.first-1][nowPoint.second] == 0){
            nowCompleteQueue.push(make_pair(nowPoint.first-1, nowPoint.second));
            arr[nowPoint.first-1][nowPoint.second] = arr[nowPoint.first][nowPoint.second]+1;
        }
        if(nowPoint.first < n-1 && arr[nowPoint.first+1][nowPoint.second] == 0){
            nowCompleteQueue.push(make_pair(nowPoint.first+1, nowPoint.second));
            arr[nowPoint.first+1][nowPoint.second] = arr[nowPoint.first][nowPoint.second]+1;
        }
        if(nowPoint.second > 0 && arr[nowPoint.first][nowPoint.second-1] == 0){
            nowCompleteQueue.push(make_pair(nowPoint.first, nowPoint.second-1));
            arr[nowPoint.first][nowPoint.second-1] = arr[nowPoint.first][nowPoint.second]+1;
        }
        if(nowPoint.second < m-1 && arr[nowPoint.first][nowPoint.second+1] == 0){
            nowCompleteQueue.push(make_pair(nowPoint.first, nowPoint.second+1));
            arr[nowPoint.first][nowPoint.second+1] = arr[nowPoint.first][nowPoint.second]+1;
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
            if(arr[i][j] == 0)return -1;
            else if(max <= arr[i][j]) max = arr[i][j];
        }
    }
    return max -1;
}
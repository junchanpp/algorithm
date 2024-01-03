#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> hexArr;
priority_queue<int, vector<int>, greater<int> > q;
int memo[1000001];

void initializeHexArr(){
    int i = 1, increment = 1;
    while(i <= N){
        hexArr.push_back(i);
        q.push(i);
        memo[i] = 1;
        increment += 4;
        i += increment;
    }
}

int main(){
    cin >> N;
    memo[11] = memo[26] = 6;
    memo[130] = 5;
    memo[146858] = 4;

    initializeHexArr();

    int hexArrSize = hexArr.size();

    while(!q.empty()){
        int num = q.top();
        q.pop();

        int nowCount = memo[num];
        if(num > 146858 && nowCount >= 3)continue;
        // if(num > 1791 && nowCount >= 4)continue;
        if(num > 130 && nowCount >= 4)continue;
        if(num > 26 && nowCount >=5)continue;

        for(int i = 0 ; i < hexArrSize && num + hexArr[i] <= N; i++){
            int nowNum = num + hexArr[i];
            if(memo[nowNum] == 0)q.push(nowNum);
            if(memo[nowNum] == 0 || nowCount+1<memo[nowNum]){
                memo[nowNum] = nowCount+1;
            }
        }
    }

    cout << memo[N];
}
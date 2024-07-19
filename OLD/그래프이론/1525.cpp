#include <iostream>
#include <set>
#include <queue>
#include <utility>

using namespace std;

int parseToSetData(int puzzle[3][3]){
    int num = 0;
    for(int i = 0; i< 3;i++){
        for(int j = 0; j<3;j++){
            num*=10;
            num+=puzzle[i][j];
        }
    }
    return num;
}
void parseToArr(int setData, int arr[3][3]){
    for(int i = 2; i>=0;i--){
        for(int j = 2; j>=0;j--){
            arr[i][j] = setData%10;
            setData/=10;
        }
    }

}

int main(){
    int puzzle[3][3];
    int initPuzzleArr[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    int initPuzzle = (parseToSetData(initPuzzleArr));

    for(int i = 0; i < 3; i++){
        for(int j = 0; j<3; j++){
            cin >> puzzle[i][j];
            if(puzzle[i][j] == 0)puzzle[i][j] = 9;
        }
    }

    set<int> visited;
    queue<pair<int, int> > q;//first: 배열정보, second: 횟수
    q.push(make_pair(parseToSetData(puzzle),0));
    if(parseToSetData(puzzle) == initPuzzle){
        cout << 0;
        return 0;
    }

    visited.insert(parseToSetData(puzzle));
    
    int dyList[]={0,0,-1,1};
    int dxList[]={-1,1,0,0};
    while(!q.empty()){
        pair<int,int> value = q.front();
        q.pop();
        int arr[3][3];
        parseToArr(value.first, arr);
        int count = value.second;
        int x;
        int y;
        for(int i = 0; i< 3; i++){
            for(int j = 0; j<3;j++){
                if(arr[i][j]==9){x =j;y=i;}
            }
        }

        for(int i = 0; i<4;i++){
            int newY = dyList[i]+ y;
            int newX = dxList[i]+ x;
            if(newY >2 || newX >2 || newY<0 || newX<0)continue;
            swap(arr[y][x], arr[newY][newX]);
            int newData = parseToSetData(arr);
            swap(arr[y][x], arr[newY][newX]);
            if(newData == initPuzzle){
                cout << count+1;
                return 0;
            } else if(visited.find(newData) != visited.end()){
                continue;
            }
            q.push(make_pair(newData,count+1));
            visited.insert(newData);
        }
    }

    cout << -1;

}
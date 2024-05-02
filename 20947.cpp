#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N;
vector<vector<int> > mapInfo;//0: 빈칸, 1: 건물, 2: 건물 잔해, -1: 폭탄

bool isDestroyedUp(int x, int y){
    if(y < 0 || mapInfo[y][x] == 2){
        return true;
    }
    if(mapInfo[y][x] == 1){
        return false;
    }
    return isDestroyedUp(x, y-1);

}

bool isDestroyedDown(int x, int y){
    if(y >= N ||mapInfo[y][x] == 2){
        return true;
    }
    if(mapInfo[y][x] == 1){
        return false;
    }
    return isDestroyedDown(x, y+1);
}


int main(){
    cin >> N;

    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        vector<int> v;
        for(int j = 0 ; j < N;j++){
            v.push_back((s[j] == '.') ? 0 : (s[j] == 'O') ? 1 : 2);
        }
        mapInfo.push_back(v);
    }


    for(int i = 0 ; i < N ; i++){
        int lastX = -1;//-1: 아직 만난 적 없음(왼쪽 끝), -2: 건물을 본 적 있음
        for(int j = 0 ; j < N; j++){
            if(j == N-1 && mapInfo[i][j] == 0 && lastX != -2){
                for(int a = lastX+1; a <= j; a++){
                    if(isDestroyedUp(a, i -1) && isDestroyedDown(a, i + 1)){
                        mapInfo[i][a] = -1;
                    }
                }
                lastX = j;
            }else if(mapInfo[i][j] == 2 && lastX != -2){
                for(int a = lastX+1; a < j; a++){
                    if(isDestroyedUp(a, i -1) && isDestroyedDown(a, i + 1)){
                        mapInfo[i][a] = -1;
                    }
                }
                lastX = j;
            } else if (mapInfo[i][j] == 2 && lastX == -2) {
                lastX = j;
            } else if(mapInfo[i][j] == 1){
                lastX = -2;
            }
        }
    }


    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N; j++){
            cout << (mapInfo[i][j] == 0 ? '.' : mapInfo[i][j] == 1 ? 'O' : mapInfo[i][j] == 2 ? 'X' : 'B');
        }
        cout << endl;
    }
}

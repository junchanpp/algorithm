//2022-02-21 23:25 start
//2022-02-22 00:25 end

#include <iostream>
#include <string>
#include <string.h>


using namespace std;
bool light[10][10];

void toggle(bool arr[][10], int y, int x){
    arr[y][x] = !arr[y][x];

    if(y+1 < 10)arr[y+1][x]=!arr[y+1][x];
    if(x+1 < 10)arr[y][x+1]=!arr[y][x+1];
    if(x-1 >= 0)arr[y][x-1]=!arr[y][x-1];
    if(y-1 >= 0)arr[y-1][x]=!arr[y-1][x];
}

bool isAllOff(bool arr[10][10]){
    bool isOff = true;
    for(int i =0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j])isOff = false;
        }
    }

    return isOff;
}

int main(){
    for(int i =0;i<10;i++){
        string s;
        cin >> s;
        for(int j =0; j<10;j++){
            if(s[j]=='O'){
                light[i][j]=true;
            }else{
                light[i][j]=false;
            }
        }
    }
    int maxCnt = -1;

    for(int i = 0; i < (1<<10);i++){
        int cnt = 0;
        bool temp[10][10];
        for(int a= 0;a<10;a++){
            for(int b=0;b<10;b++){
                temp[a][b] = light[a][b];
            }
        }
        for(int a = 0;a < 10; a++){
            if(i & (1 << a)){
                cnt++;
                toggle(temp,0,a);
            }
        }

        for(int i = 1; i < 10;i++){
            for(int j = 0;j<10;j++){
                if(temp[i-1][j]){
                    cnt++;
                    toggle(temp,i,j);
                }
            }
        }


        if(isAllOff(temp)){
            if(maxCnt == -1)maxCnt = cnt;
            else if(maxCnt > cnt)maxCnt = cnt;
        }
    }

    cout << maxCnt;

}
#include <iostream>
#include <string>
using namespace std;

int R,C;
bool visited[10000][500];
bool solve(int y, int x){
    if(x == C)return true;
    if(y >= R || y < 0 || visited[y][x])return false;
    visited[y][x] = true;
    return solve(y-1,x+1) || solve(y,x+1) || solve(y+1,x+1);
}

int main(){
    cin >> R >> C;

    for(int i = 0; i< R; i++){
        string s;
        cin >> s;
        
        for(int j = 0; j < C;j++){
            visited[i][j] = (s[j] =='x');
        }
    }
    int count = 0;
    for(int i = 0; i< R;i++){
        if(solve(i,0))count++;
    }

    cout << count;
}
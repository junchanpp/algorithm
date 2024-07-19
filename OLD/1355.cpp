#include <iostream>
#include <cmath>
#include <vector>
#define ADD 100

using namespace std;

int lc, lh;
int h, v;
vector<int> hList, vList;
int lineX[100+ADD];//수평
int lineY[100+ADD];//수직
int cake[101+ADD][101+ADD];

void dfs(int i, int j){
    if(i < lc*(-1) || i > lc || j < lc*(-1) || j > lc){
        return;
    }
    if(cake[i+ADD][j+ADD]==0)return;
    cake[i+ADD][j+ADD] = 0;
    if(i > 0 && !lineX[i+ADD])dfs(i+1,j);
    if(i > 0 && !lineX[i-1+ADD])dfs(i- (i == 1 ? 2 : 1),j);
    if(j > 0 && !lineY[j+ADD])dfs(i,j+1);
    if(j > 0 && !lineY[j-1+ADD])dfs(i,j- (j == 1 ? 2 :1));
    if(i < 0 && !lineX[i+1+ADD])dfs(i+ (i == -1 ? 2 : 1),j);
    if(i < 0 && !lineX[i+ADD])dfs(i-1,j);
    if(j < 0 && !lineY[j+1+ADD])dfs(i,j+(j== -1 ? 2: 1));
    if(j < 0 && !lineY[j+ADD])dfs(i,j-1);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> lc >> lh;

    for(int i = -100; i <= 100; i++){
        for(int j = -100; j <= 100; j++){
            if(abs(i) <= lh && abs(j) <= lh){
                cake[i+ADD][j+ ADD] = 0;
            }else {
                cake[i+ADD][j+ADD] = 1;
            }
        }
    }
    
    cin >> h;
    hList.resize(h);
    for(int i = 0 ; i < h; i++){
        int temp;
        cin >> temp;
        lineX[temp+ADD] = 1;
    }

    cin >> v;
    vList.resize(h);
    for(int i = 0 ; i < v; i++){
        int temp;
        cin >> temp;
        lineY[temp+ADD] = 1;
    }

    int sum = 0;
    for(int i = -1 *lc ; i <= lc; i++){
        if(i== 0)continue;
        for(int j = -1 * lc; j <= lc; j++){
            if(j == 0)continue;
            if(cake[i+ADD][j+ADD] == 1){
                dfs(i,j);
                sum++;
            }
        }
    }

    cout << sum;
}
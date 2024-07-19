#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int A, B ,C;
bool visited[300][300][300];
vector<int> v;
void solve(int a, int b, int c){
    if(visited[a][b][c] == true)return;
    if(a== 0){ 
        v.push_back(c);
    }
    visited[a][b][c] = true;
    //A
    int AtoB = min(a,B-b);
    solve(a-AtoB,b+AtoB,c);
    int AtoC = min(a,C-c);
    solve(a-AtoC,b,c+AtoC);
    //B
    int BtoA = min(A-a,b);
    solve(a+BtoA,b-BtoA,c);
    int BtoC = min(b,C-c);
    solve(a,b-BtoC,c+BtoC);
    //C
    int CtoA = min(A-a,c);
    solve(a+CtoA,b,c-CtoA);
    int CtoB = min(B-b,c);
    solve(a,b+CtoB,c-CtoB);
}
int main(){
    cin >> A >> B >> C;
    for(int i = 0; i < 300;i++){
        for(int j = 0; j<300;j++){
            memset(visited[i][j],0, sizeof(visited[i][j]));
        }
    }
    solve(0,0,C);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0; i <v.size();i++){
        cout << v[i]<< " ";
    }
}
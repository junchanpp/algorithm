#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N,M;

int parent[1001];

int find(int x){
    if(parent[x]<=0)return x;
    else return parent[x] = find(parent[x]);
}
void merge(int x, int y){
    
    x = parent[x] == 0 ? x : find(x);
    y = parent[y] == 0 ? y : find(y);
    if(x==y)return;
    if(x >= y){
        parent[x]+=parent[y];
        parent[y] = x;
    }else {
        parent[y]+=parent[x];
        parent[x] = y;
    }
    for(int i = 1; i<=N;i++){
        find(i);
    }
}

int main(){
    cin >> N >> M;
    fill(parent,parent+1001,-1);
    vector<int> E[N+1];
    for(int i = 0; i < M;i++){
        char R;
        int num1,num2;
        cin >> R >> num1 >> num2;
        bool isFriend = R=='F';
        if(isFriend)merge(num1,num2);
        else {E[num1].push_back(num2); E[num2].push_back(num1);}
    }

    for(int i = 1; i <= N;i++){
        int size = E[i].size();
        for(int j = 0; j<size-1;j++){
            int f1 = find(E[i][j]);
            int f2 = find(E[i][j+1]);
            if(f1==f2)continue;
            merge(E[i][j],E[i][j+1]);
        }
    }
    int count = 0;
    for(int i = 1 ; i<=N;i++){
        if(parent[i]<=0)count++;
    }
    cout <<count;
}
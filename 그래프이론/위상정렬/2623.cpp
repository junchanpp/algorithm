#include <iostream>
#include <vector>
#define MAX = 1001;

using namespace std;

int N, M;
vector<int> v[1001];
int degree[1001] = {0,};
int visited[1001] = {0,};
vector<int> ans;
void solve(int n){
    ans.push_back(n);
    visited[n] = 1;
    if(v[n].empty())return;

    for(int i = 0; i < v[n].size();i++){
        degree[v[n][i]]--;
        if(degree[v[n][i]]==0){
            solve(v[n][i]);
        }
    }
    return;
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int K;
        scanf("%d", &K);
        int temp;
        int newTemp;
        for(int k = 0; k < K; k++){
            scanf("%d", &newTemp);
            if(k==0){temp = newTemp;continue;}
            degree[newTemp]++;
            v[temp].push_back(newTemp);
            temp = newTemp;
        }
    }
    for(int i = 1; i < N+1;i++){
        if(degree[i] == 0 && visited[i]==0){
            solve(i);
        }
    }

    if(ans.size() != N){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i< ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
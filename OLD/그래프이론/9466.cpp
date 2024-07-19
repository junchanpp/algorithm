#include <iostream>
#include <string.h>
#define MAX 1000001
using namespace std;
int arr[MAX]= {0,};
bool visited[MAX] = {0,};
bool done[MAX] = {0,};
int cnt = 0;

void check(int i){
    if(visited[i])return;
    visited[i] = true;

    if(!visited[arr[i]]){
        check(arr[i]);
    } else if(!done[arr[i]]){
        for(int j = arr[i]; j != i; j = arr[j]){
            cnt++;
        }
        cnt++;
    }
    done[i] = true;
    
}

int main(){
    int T;
    cin >> T;

    for(int i = 0 ; i < T; i++){
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        cnt = 0;
        int n;
        scanf("%d", &n);
        for(int j = 1; j < n+1; j++){
            scanf("%d", &arr[j]);
        }
        for(int j = 1; j < n+1; j++){
            if(visited[j])continue;
            check(j);
        }

        cout << n - cnt << endl;
    }
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

vector<vector<int> > children;
int oddCount = 0;

void solve(int num, int flag){
    if(flag){
        oddCount++;
    }
    for(int i = 0 ; i < children[num].size(); i++){
        solve(children[num][i], !flag);
    }
}

int main(){
    cin >> N;
    children.assign(N+1, vector<int>(0));

    int input;
    for(int i = 2 ; i <= N; i++){
        cin >> input;
        children[input].push_back(i);
    }

    solve(1, 0);

    cout << max(oddCount, N- oddCount);
}
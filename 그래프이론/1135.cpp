#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> children[51];

int solve(int node){
    if(children[node].empty())return 0;

    int size = children[node].size();
    vector<int> time;

    for(int i = 0 ; i < size;i++){
        time.push_back(solve(children[node][i]));
    }

    sort(time.begin(),time.end(), greater<int>());

    for(int i = 0; i < size;i++){
        time[i]+=(i+1);
    }
    int max = 0;
    for(int i = 0; i < size; i++){
        if(max < time[i])max = time[i];
    }
    return max;
}

int main(){
    cin >> N;
    for(int i = 0; i< N;i++){
        int temp;
        cin >> temp;
        if(temp == -1)continue;

        children[temp].push_back(i);
    }

    cout << solve(0);
}
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, bool>& a,pair<int, bool>& b){
        return a.first > b.first;
    }
};

int solve(int N, vector<pair<int,bool> > arr){
    vector<int> indegree(N+1,0);
    for(int i = 0 ; i < N;i++){
        indegree[arr[i].first]++;
    }
    
    vector<bool> visited(N+1, 0);
    int count = 0;

    vector<int> plusAlienIfAlien(N+1,0);
    vector<int> plusAlienIfPerson(N+1,0);
    for(int i = 1; i i <= N; i++){
        
    }

    for(int i = 1; i <= N; i++){
        if(visited[i]){
            continue;
        }
        queue<pair<int, bool> > q;
        q.push(make_pair(i, true));//i번 사람이 외계인이라 가정
        int alienCount = 1;
        int totalCount = 1;
    
        while(!q.empty()){
            int index = q.front().first;
            bool isAlien = q.front().second;
            q.pop();
            if(visited[arr[index].first] != 0){
                continue;
            }
            visited[arr[index].first] = isAlien ? !arr[index].second : arr[index].second;
            q.push(make_pair(arr[index].first, isAlien ? !arr[index].second : arr[index].second));
            if(isAlien ? !arr[index].second : arr[index].second){
                cout << arr[index].first << endl;//7이 걸림
                alienCount++;
            }
            totalCount++;
        }
    }


    if(totalCount - alienCount < alienCount){
        alienCount = totalCount - alienCount;
    }

    count +=alienCount;

    

    return count;
}

int main(){
    int N;
    cin >> N;
    vector<pair<int,bool> > arr(N);
    
    for(int i = 0 ; i  < N; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    cout << solve(N, arr) << endl;
}
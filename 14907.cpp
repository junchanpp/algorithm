#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> indegree;
vector<int> memo;
vector<int> cost;
vector<vector<int> > arr;


int solve();

int main(){
    string s;
    
    indegree.assign(26,0);
    memo.assign(26,0);
    cost.assign(26,0);
    arr.assign(26,vector<int>(0));

    while(getline(cin, s)){
        if(cin.eof() || s.size() == 0){
            break;
        }
        
        char end = s[0];
        int c = stoi(s.substr(2));
        cost[end- 'A'] = c;
        
        int index = 0;
        int countWord = 0;
        while(s.size() != index && countWord != 2){
            if(s[index] == ' '){
                countWord++;
            }
            index++;
        }
        if(countWord != 2){
            continue;
        }

        for(int i = index ; i < s.size(); i++){
            indegree[end-'A']++;
            arr[s[i]-'A'].push_back(end- 'A');
        }
    }

    cout << solve();

}


int solve(){
    queue<int> q;
    for(int i = 0 ; i < 26; i++){
        if(indegree[i] == 0 && cost[i] != 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int index = q.front();
        q.pop();

        for(int i = 0 ; i < arr[index].size();i++){
            int nextIndex = arr[index][i];
            int nextCost = cost[index] + memo[index];
            if(memo[nextIndex] < nextCost){
                memo[nextIndex] = nextCost;
            }
            if(--indegree[nextIndex] == 0){
                q.push(nextIndex);
            }
        }
    }

    int max = 0;
    for(int i = 0 ; i < 26; i++){
        if(cost[i] + memo[i] > max){
            max = cost[i] + memo[i];
        }
    }

    return max;
}
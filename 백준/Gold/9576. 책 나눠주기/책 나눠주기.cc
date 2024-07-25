#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
vector<pair<int,int> > inputs;
vector<int> assigned;
vector<bool> done;

int dfs(int index){
    for(int i = inputs[index].first; i <= inputs[index].second; i++){
        if(done[i]){
            continue;
        }
        done[i] = true;
        if(assigned[i] == INT_MAX || dfs(assigned[i])){
            assigned[i] = index;
            return true;
        }
    }
    return false;
}

void problem(){
    cin >> N >> M;
    inputs.clear();
    assigned.clear();
    done.clear();

    assigned.assign(N,INT_MAX);

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        inputs.push_back(make_pair(a,b));
    }

    sort(inputs.begin(), inputs.end());

    int answer = 0;

    for(int i = 0; i < M; i++){
        done.assign(N, 0);
        if(dfs(i)){
            answer++;
        }
    }

    cout << answer << '\n';
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--){
        problem();
    }
    
}
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<bool> > isFriend;
vector<int> parent;

int find(int a){
    if(parent[a] < 0){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        return;
    }
    parent[b] += parent[a];
    parent[a] = b;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;

    isFriend.assign(N+1, vector<bool>(N+1,0));
    parent.assign(N+1, -1);

    int a = 0, b = 0;
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1){
            break;
        }
        isFriend[a][b] = 1;
        isFriend[b][a] = 1;
    }

    bool isAllFriend = true;

    for(int i = 1; i <= N; i++){
        vector<int> notFriends;
        for(int j = 1; j <= N; j++){
            if(i == j || isFriend[i][j]){
                continue;
            }
            isAllFriend = false;
            notFriends.push_back(j);
        }

        for(int j = 1; j < notFriends.size(); j++){
            union_set(notFriends[0], notFriends[j]);
        }
    }
    if(isAllFriend){
        for(int i = 1; i < N; i++){
            union_set(i,i+1);
        }
    }
    



    int parent1 = find(1);
    int parent2 = -1;
    set<int> parentSet;

    for(int i = 1; i <= N; i++){
        parentSet.insert(find(i));
        if(parent1 != find(i)){
            parent2 = find(i);
        }
        for(int j = i + 1; j <= N; j++){
            if(find(i) == find(j) && !isFriend[i][j]){
                cout << -1;
                return 0;
            }
        }
    }

    if(parentSet.size() > 2){
        cout << -1;
        return 0;
    }

    cout << 1 << '\n';
    for(int i = 1; i<=N; i++){
        if(parent1 == find(i)){
            cout << i << " ";
        }
    }
    cout << -1 << '\n';
    
    for(int i = 1; i <= N; i++){
        if(parent2 == find(i)){
            cout << i << " ";
        }
    }

    cout << -1 << '\n';
}
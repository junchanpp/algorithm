#include <iostream>
#include <vector>
#define NODE_MAX 1000001

using namespace std;
vector<int> parents;

int find(int a){
    if(parents[a] < 0){
        return a;
    }
    return parents[a] = find(parents[a]);
}

void unionParent(int a, int b){
    a = find(a);
    b = find(b);
    if(a== b){
        return;
    }
    parents[a]+= parents[b];
    parents[b] = a;
}
int getCount(int a){
    return parents[find(a)] * -1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    parents.assign(NODE_MAX, -1);
    while(N--){
        char command;
        cin >> command;
        if(command == 'I'){
            int a,b;
            cin >> a >> b;
            unionParent(a,b);
        }else {
            int c;
            cin >> c;
            cout << getCount(c) << '\n';
        }
    }
    return 0;
}
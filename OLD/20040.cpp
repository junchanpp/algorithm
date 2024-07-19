#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
int* node;

int find(int i){
    if(node[i] < 0){
        return i;
    }
    return node[i] = find(node[i]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)return;

    if(node[a] > node[b]){
        node[a] = b;
    }
    else {
        if(node[a]==node[b]){
            node[a]--;
        }
        node[b] = a;
    }
}

void print(int i){
    cout << i+1 << endl;
}

int main(){
    cin >> n >> m;
    int arr[n];
    node = arr;
    for(int i = 0; i< n; i++){
        node[i] = -1;
    }

    for(int i = 0 ; i < m ; i++){
        register int a,b;
        cin >> a >> b;
        if(find(a)==find(b)){
            print(i);
            return 0;
        }
        merge(a,b);
    }

    cout << 0 << endl;
    return 0;
}
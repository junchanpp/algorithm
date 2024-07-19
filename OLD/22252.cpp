#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

unordered_map<string, priority_queue<int> > hmap;

void insertInfo(){
    string key;
    int count;
    cin >> key >> count;
    if(hmap.end() == hmap.find(key)){
        priority_queue<int> pq;
        hmap.insert(make_pair(key, pq));
    }

    for(int i = 0; i < count ; i++){
        int temp;
        cin >> temp;
        (*hmap.find(key)).second.push(temp);
    }
}

long long takeInfo(){
    string key;
    int count;
    cin >> key >> count;
    if(hmap.end() == hmap.find(key)){
        return 0;
    }

    long long sum = 0;
    for(int i = 0; i < count ; i++){
        if((*hmap.find(key)).second.size() == 0){
            break;
        }
        sum += (*hmap.find(key)).second.top();
        (*hmap.find(key)).second.pop();
    }
    return sum;
}

int main(){
    int Q;
    cin >> Q;

    long long sum = 0;
    for(int i = 0 ; i < Q; i++){
        int type;
        cin >> type;
        if(type == 1){
            insertInfo();
        } else {
            sum += takeInfo();
        }
    }

    cout << sum;
}
#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

typedef struct Picture{
    int visited;
    int cost;
    int pos;
}Picture;

bool operator<(const Picture& p, const Picture& q){
        if(p.visited == q.visited){
            if(p.cost == q.cost)return p.pos < q.pos;
            return p.cost < q.cost;
        }
        return p.visited < q.visited;
}

Picture makePicture(int visited, int cost, int pos){
    Picture p = {visited,cost,pos};
    return p;
}

int N;
int cost[15][15] = {0,};
int counted = 0;
set<Picture> visited;
int addBit(const int& bit, const int& pos){
    return bit | 1<<pos;
}
bool isExist(const int& bit, const int& pos){
    return bit & (1<<pos);
}
int countPerson(const int& bit){
    int c = 0;
    for(int i = 0 ; i < N ; i++){
        if(isExist(bit,i))c++;
    }
    return c;
}
int main(){
    cin >> N;
    for(int i = 0; i < N ; i++){
        string s;
        cin >>s;
        for(int j = 0 ; j < N ; j++){
            cost[i][j] = s[j]-'0';
        }
    }
    queue<Picture> q;
    q.push(makePicture(1>>0,0,0));
    while(!q.empty()){
        Picture p = q.front();
        q.pop();
        if(visited.find(p)!=visited.end())continue;
        visited.insert(p);
        if(counted < countPerson(p.visited))counted = countPerson(p.visited);
        for(int i = 0 ; i < N; i++){
            if(i==p.pos || isExist(p.visited, i) || cost[p.pos][i] < p.cost)continue;
            q.push(makePicture(addBit(p.visited, i), cost[p.pos][i], i));
        }
    }
    cout << counted;
}
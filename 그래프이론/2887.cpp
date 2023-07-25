#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

struct Edge{
    int cost;
    int a, b;
};

struct Planet{
    int number;
    int x,y,z;
};

bool compareX(const Planet& a, const Planet& b) {return a.x < b.x;}
bool compareY(const Planet& a, const Planet& b) {return a.y < b.y;}
bool compareZ(const Planet& a, const Planet& b) {return a.z < b.z;}
bool compareCost(const Edge& a, const Edge& b) {return a.cost < b.cost;}

int parentNode[MAX];
int N;
vector<Planet> p;
vector<Edge> e;
int find(int node){
    if(parentNode[node] < 0)return node;
    return parentNode[node] = find(parentNode[node]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b)return;
    
    if(parentNode[a] > parentNode[b]){
        parentNode[a]= b;
    }
    else {
        if(parentNode[a]==parentNode[b]){
            parentNode[a]--;
        }
        parentNode[b] = a;
    }
}
int main(){
    cin >> N;

    for(int i = 0 ; i< N; i++){
        parentNode[i] = -1;
    }

    for(int i = 0 ; i< N; i++){
        Planet planet = Planet();
        scanf("%d %d %d", &planet.x, &planet.y, &planet.z);
        planet.number = i;
        p.push_back(planet);
    }

    sort(p.begin(), p.end(),compareX);
    for(int i = 0; i< N-1; i++){
        Edge edge = {abs(p[i].x-p[i+1].x),p[i].number,p[i+1].number};
        e.push_back(edge);
    }
    sort(p.begin(), p.end(),compareY);
    for(int i = 0; i< N-1; i++){
        Edge edge = {abs(p[i].y-p[i+1].y),p[i].number,p[i+1].number};
        e.push_back(edge);
    }
    sort(p.begin(), p.end(),compareZ);
    for(int i = 0; i< N-1; i++){
        Edge edge = {abs(p[i].z-p[i+1].z),p[i].number,p[i+1].number};
        e.push_back(edge);
    }

    sort(e.begin(), e.end(), compareCost);

    int size = e.size();
    int sum = 0;
    for(int i = 0; i < size; i++){
        
        if(find(e[i].a) != find(e[i].b)){
            sum+=e[i].cost;
            merge(e[i].a,e[i].b);
        }
    }
    cout << sum << endl;
}
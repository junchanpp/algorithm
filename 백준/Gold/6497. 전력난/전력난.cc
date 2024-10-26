#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



typedef struct Node{
    int distance;
    int x;
    int y;

    Node(int distance, int x, int y): distance(distance), x(x), y(y){}
}Node;

bool compare(const Node& a, const Node& b){
    return a.distance < b.distance;
}

vector<Node> nodes;
 
vector<int> parents;

int M, N;



int find(int x){
    if(parents[x] < 0){
        return x;
    }
    return parents[x] = find(parents[x]);
}

bool isEqualParent(int x, int y){
    return find(x) == find(y);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(parents[x] <= parents[y]){
        parents[x] += parents[y];
        parents[y] = x;
    }else{
        parents[y] += parents[x];
        parents[x] = y;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    
    while(1){
        cin >> M >> N;
        if(N == 0 && M == 0){
            return 0;
        }

        parents.clear();
        parents.assign(M, -1);

        nodes.clear();

        for(int i = 0; i < N; i++){
            int x, y, z;
            cin >> x >> y >> z;
            nodes.push_back(Node(z, x, y));
        }

        sort(nodes.begin(), nodes.end(), compare);


        int result = 0;

        for(int i = 0; i < nodes.size(); i++){
            int x = nodes[i].x;
            int y = nodes[i].y;
            int distance = nodes[i].distance;
            if(isEqualParent(x,y)){
                result += distance;
            }else {
                merge(x,y);
            }
        }

        cout << result << '\n';
    }

    return 0;
}
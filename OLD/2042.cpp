#include <iostream>
#include <vector>

using namespace std;
int N, M, K;
vector<long long> initTree;
vector<long long> segmentTree;

void init();
long long init(int start, int end, int node);
void update(int index,long long newNum);
long long sum(int start, int end);
long long sum(int start, int end, int node, int left, int right);
void update(int start, int end, int node, int index, long long diff);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;
    initTree.assign(N,0);
    segmentTree.assign(4 * N, 0);
    for(int i = 0 ; i < N; i++){
        cin >> initTree[i];
    }

    init();

    vector<long long> answers;

    for(int i = 0; i < M+K; i++){
        long long type, a, b;
        cin >> type >> a >> b;
        if(type == 1){
            update(a,b);
        } else {
            answers.push_back(sum(a,b));
        }
    }

    for(int i = 0 ; i < answers.size(); i++){
        cout << answers[i] << endl;
    }
}

void init(){
    init(0,N-1,1);
}

long long init(int start, int end, int node){
    if(start == end) return segmentTree[node] = initTree[start];
    int mid = (start+end)/2;
    return segmentTree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}

long long sum(int left, int right){
    return sum(0,N-1,1,left-1,right-1);
}

long long sum(int start, int end, int node, int left, int right){
    if(left > end || right < start)return 0;
    else if(left <= start && right >= end)return segmentTree[node];
    int mid = (start + end) / 2;
    return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);
}

void update(int index,long long newNum){
    long long diff = newNum - initTree[index-1];
    initTree[index-1] = newNum;
    update(0,N-1, 1, index-1, diff);
}

void update(int start, int end, int node, int index, long long diff){
    int mid = (start + end) / 2;
    if(index > end || index < start)return;
    segmentTree[node] += diff;
    if(start == end)return;
    update(start,mid,node*2,index,diff);
    update(mid+1,end,node*2+1,index,diff);
}
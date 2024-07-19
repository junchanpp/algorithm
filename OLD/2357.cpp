#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>

using namespace std;

vector<int> A;
int N, M;
vector<int> tree;
vector<int> treeMax;

void initTree();
int initTree(int start, int end, int node);
int getMin(int left, int right);
int getMin(int start, int end, int node, int left, int right);
void initTreeMax();
int initTreeMax(int start, int end, int node);
int getMax(int left, int right);
int getMax(int start, int end, int node, int left, int right);
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    A.assign(N,0);
    tree.assign(4*N,0);//tree[i] = A[tree[2*i]] <= A[tree[2*i+1]] ? A[tree[2*i]] : A[tree[2*i+1]], <=로 크기가 같으면 인덱스 작은 애가 오게 됨.
    treeMax.assign(4*N,0);

    for(int i = 0 ; i < N; i++){
        cin >> A[i];
    }
    initTree();
    initTreeMax();
    
    vector<pair<int,int> > answers;
    for(int i = 0; i < M;i++){
        int left, right;
        cin >> left >> right;
        int first = getMin(left,right);
        int second = getMax(left,right);
        answers.push_back(make_pair(first,second));
    }

    for(int i = 0 ; i < answers.size(); i++){
        cout << answers[i].first << " " << answers[i].second << '\n';
    }
}

void initTree(){
    initTree(0,N-1,1);
}
int initTree(int start, int end, int node){
    if(start == end){
        return tree[node] = start;
    }
    int mid = (start + end) / 2;
    return tree[node] = A[initTree(start, mid,2*node)] <= A[initTree(mid+1,end,2*node+1)] ? tree[2*node] : tree[2*node+1];
}

int getMin(int left, int right){
    return A[getMin(0,N-1,1,left-1,right-1)];
}
int getMin(int start, int end, int node, int left, int right){
    if(right < start || left > end){
        return INT_MAX;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    int mid = (start + end) / 2;

    int firstIndex = getMin(start, mid, 2*node, left, right);
    int secondIndex = getMin(mid+1, end, 2*node+1, left, right);
    
    if(secondIndex == INT_MAX){
        return firstIndex;
    } else if(firstIndex == INT_MAX){
        return secondIndex;
    }
    return A[firstIndex] <= A[secondIndex] ? firstIndex : secondIndex;
}


void initTreeMax(){
    initTreeMax(0,N-1,1);
}
int initTreeMax(int start, int end, int node){
    if(start == end){
        return treeMax[node] = start;
    }
    int mid = (start + end) / 2;
    return treeMax[node] = A[initTreeMax(start, mid,2*node)] >= A[initTreeMax(mid+1,end,2*node+1)] ? treeMax[2*node] : treeMax[2*node+1];

}
int getMax(int left, int right){
    return A[getMax(0,N-1,1,left-1,right-1)];
}
int getMax(int start, int end, int node, int left, int right){
    if(right < start || left > end){
        return INT_MIN;
    }
    if(left <= start && end <= right){
        return treeMax[node];
    }
    int mid = (start + end) / 2;

    int firstIndex = getMax(start, mid, 2*node, left, right);
    int secondIndex = getMax(mid+1, end, 2*node+1, left, right);
    
    if(secondIndex == INT_MIN){
        return firstIndex;
    } else if(firstIndex == INT_MIN){
        return secondIndex;
    }
    return A[firstIndex] >= A[secondIndex] ? firstIndex : secondIndex;
}
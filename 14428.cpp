#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> A;
int N;
vector<int> tree;

void initTree();
int initTree(int start, int end, int node);
void update(int index);
void update(int start, int end, int node, int index);
int getMin(int left, int right);
int getMin(int start, int end, int node, int left, int right);
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    A.assign(N,0);
    tree.assign(4*N,0);//tree[i] = A[tree[2*i]] <= A[tree[2*i+1]] ? A[tree[2*i]] : A[tree[2*i+1]], <=로 크기가 같으면 인덱스 작은 애가 오게 됨.

    for(int i = 0 ; i < N; i++){
        cin >> A[i];
    }
    initTree();
    
    int M;
    cin >> M;
    vector<int> answers;
    for(int i = 0; i < M;i++){
        int type;
        cin >> type;
        if(type == 1){
            int index, newNum;
            cin >> index >> newNum;//입력 시 index가 +1되어 들어옴을 유의
            index--;
            A[index] = newNum;
            update(index);
        }else {
            int left, right;
            cin >> left >> right;//입력 시 index가 +1되어 들어옴을 유의
            answers.push_back(getMin(left-1, right-1));
        }
    }

    for(int i = 0 ; i < answers.size(); i++){
        cout << answers[i] << '\n';
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
void update(int index){
    update(0,N-1,1,index);
}
void update(int start, int end, int node, int index){
    if(index < start || end < index){
        return;
    }
    if(start == end){
        return;
    }
    int mid = (start+end) / 2;

    update(start, mid, 2*node, index);
    update(mid+1, end, 2*node+1, index);
    tree[node] = A[tree[2*node]] <= A[tree[2*node+1]] ? tree[2*node] : tree[2*node+1];
}
int getMin(int left, int right){
    return getMin(0,N-1,1,left,right)+1;
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
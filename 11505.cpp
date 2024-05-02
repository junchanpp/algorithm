#include <iostream>
#include <vector>
#define MOD_NUM 1000000007

using namespace std;

int N, M, K;

vector<int> arr;
vector<long long> tree;

void initTree();
long long initTree(int start, int end, int N);
void update(int index, int diff);
void update(int start, int end, int N, int index, int diff);
long long mul(int left, int right);
long long mul(int start, int end, int N, int left, int right);

int main(){
    cin >> N >> M >> K;

    arr.assign(N,0);
    tree.assign(4*N,0);

    for(int i = 0 ; i < N; i++){
        cin >> arr[i];
    }

    initTree();

    vector<long long> answers;

    for(int i = 0 ; i <M+K; i++){
        int type;
        cin >> type;
        if(type == 1){
            int index, newNum;
            cin >> index >> newNum;
            index--;
            int diff = newNum - arr[index];
            update(index, diff);
            arr[index] += diff;
        }else {
            int start, end;
            cin >> start >> end;
            start--;
            end--;
            answers.push_back(mul(start, end));
        }
    }

    for(int i = 0 ; i < answers.size(); i++){
        cout <<answers[i] << endl;
    }
}

void initTree(){
    initTree(0, N-1, 1);
}

long long initTree(int start, int end, int N){
    if(start == end){
        return tree[N] = arr[start];
    }
    int mid = (start+end)/2;

    return tree[N] = (initTree(start,mid,2*N) * initTree(mid+1, end, 2*N+1)) % MOD_NUM;
}
void update(int index, int diff){
    update(0, N-1, 1, index, diff);
}
void update(int start, int end, int N, int index, int diff){
    if(index < start || index > end){
        return;
    }
    if(start == end){
        tree[N] += diff;
        return;
    }
    int mid = (start+end)/2;
    update(start, mid, 2*N, index, diff);
    update(mid+1, end, 2*N+1, index, diff);
    tree[N] = (tree[2*N]*tree[2*N+1]) % MOD_NUM;
}
long long mul(int left, int right){
    return mul(0,N-1, 1, left, right);
}
long long mul(int start, int end, int N, int left, int right){
    if(right < start || left > end){
        return 1;
    }
    if(left <= start && end <= right){
        return tree[N];
    }

    int mid = (start + end)/2;
    return (mul(start, mid, 2*N, left,right) * mul(mid+1, end,2*N+1,left,right)) % MOD_NUM;

}
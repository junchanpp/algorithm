#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> presents;
vector<int> presentCountList;
vector<int> segTree;
int N, M;
int maxValue = 0;

void initSegTree();
int initSegTree(int start, int end, int N);
int getIndex(int rank);
int getIndex(int start, int end, int N, int rank);
void update(int index, int diff);
void update(int start, int end, int N, int index, int diff);

int main(){
    cin >> N >> M;

    
    presents.assign(N,0);

    for(int i = 0; i < N; i++){
        cin >> presents[i];
        if(maxValue < presents[i]){
            maxValue = presents[i];
        }
    }

    initSegTree();

    vector<pair<int, int> > children(M,make_pair(0,0));
    for(int i = 0 ; i < M; i++){
        cin >> children[i].first;
    }

    for(int i = 0 ; i < M; i++){
        cin >> children[i].second;
    }
    
    for(int i = 0; i < M; i++){
        int requiredRank = children[i].second;
        int requiredAmount = children[i].first;
        int amount = getIndex(requiredRank);
        
        if(requiredAmount > amount){
            cout << 0 << endl;
            return 0;
        }
        
        update(amount, -1);
        update(amount-requiredAmount, 1);
    }

    cout << 1 << endl;
    return 0;
}

void initSegTree(){
    presentCountList.assign(maxValue+1, 0);
    segTree.assign(4*maxValue,0);

    for(int i = 0 ; i < presents.size(); i++){
        presentCountList[presents[i]]++;
    }
    initSegTree(0, maxValue, 1);
}

int initSegTree(int start, int end, int N){
    if(start == end){
        return segTree[N] = presentCountList[start];
    }
    int mid = (start+end)/2;
    return segTree[N] = initSegTree(start,mid,N*2) + initSegTree(mid+1, end, N*2+1);
}

int getIndex(int rank){
    return getIndex(0,maxValue,1,rank);
}


int getIndex(int start, int end, int N, int rank){
    if(start == end){
        return start;
    }
    int mid = (start+end)/2;
    if(segTree[N*2+1] >= rank){
        return getIndex(mid+1, end, N*2+1, rank);
    } else {
        return getIndex(start,mid,N*2, rank - segTree[N*2+1]);
    }
}

void update(int index, int diff){
    update(0, maxValue, 1, index, diff);
}

void update(int start, int end, int N, int index, int diff){
    if(index < start || index > end){
        return;
    }

    segTree[N] += diff;
    if(start == end){
        return;
    }
    int mid = (start+end)/2;
    update(start,mid,2*N,index,diff);
    update(mid+1,end,2*N+1,index,diff);

}
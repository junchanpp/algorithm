#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> tops;
vector<long long> bottoms;
vector<long long> bottomIndexs;
vector<long long> tree;

long long sum(int left, int right);
long long sum(int start, int end, int N, int left, int right);
void update(int index, int diff);
void update(int start, int end, int N, int index, int diff);

int main(){
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0); 
    
    cin >> N;
    tops.assign(N,0);
    bottoms.assign(N,0);
    bottomIndexs.assign(1000001,0);

    tree.assign(4*N,0);
    for(int i = 0; i < N;i++){
        cin >> tops[i];
    }
    for(int i = 0; i < N;i++){
        cin >> bottoms[i];
        bottomIndexs[bottoms[i]] = i;
    }

    long long count = 0;
    for(int i = 0; i<N; i++){
        int bottomIndex = bottomIndexs[tops[i]];
        cout << tops[i] << " " << bottomIndex << " " <<sum(bottomIndex+1, N-1) << endl;
        count += sum(bottomIndex+1, N-1);
        update(bottomIndex,1);
    }
    cout << count << endl;
}

long long sum(int left, int right){
    return sum(0,N-1,1,left,right);
}

long long sum(int start, int end, int N, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[N];
    }
    int mid = (start + end)/2;
    return sum(start, mid, 2*N, left,right) + sum(mid+1, end,2*N+1, left, right);
}


void update(int index, int diff){
    update(0, N-1, 1, index, diff);
}

void update(int start, int end, int N, int index, int diff){
    if(index < start || end < index){
        return;
    }
    tree[N] += diff;
    if(start == end){
        return;
    }
    int mid = (start + end)/2;
    update(start,mid,2*N,index,diff);
    update(mid+1, end,2*N+1,index,diff);
}
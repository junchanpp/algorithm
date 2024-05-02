#include <iostream>
#include <vector>

using namespace std;

int T;
int n,m;
int treeEnd;
vector<int> movieIndexList;//키는 고정값, 원소가 변하는 값.
vector<int> tree;//트리에는 8*n크기를 갖고있음. 
vector<vector<int> > totalAnswers;

int initTree(int start, int end, int N);

void update(int index, int diff);
void update(int start, int end, int N, int index, int diff);
int sum(int left, int right);
int sum(int start, int end, int N, int left, int right);

int main(){
    cin >> T;
    for(int a = 0 ; a < T; a++){
        cin >> n >> m;
        
        movieIndexList.assign(n+1,0);

        treeEnd = n+m;
        tree.assign(4*(treeEnd),0);

        for(int i = 1 ; i <= n;i++){
            movieIndexList[i] = n-i+1;
        }
        
        initTree(0, treeEnd, 1);

        int nextInsertTreeIndex = n+1;

        vector<int> answers;

        for(int i = 0 ; i < m; i++){
            int movieIndex;
            cin >> movieIndex;
            answers.push_back(sum(movieIndexList[movieIndex]+1, nextInsertTreeIndex));
            update(movieIndexList[movieIndex], -1);
            update(nextInsertTreeIndex, 1);
            movieIndexList[movieIndex] = nextInsertTreeIndex;
            nextInsertTreeIndex++;
        }
        totalAnswers.push_back(answers);
    }
    for(int i = 0 ; i < T; i++){
        for(int j = 0; j< totalAnswers[i].size(); j++){
            cout << totalAnswers[i][j] << " ";
        }cout << endl;
    }
}

int initTree(int start, int end, int N){
    if(start == end){
        if(start == 0){
            return tree[N] = 0;
        }
        return tree[N] = start <= n ? 1 : 0;
    }
    int mid = (start + end)/2;
    return tree[N] = initTree(start,mid,2*N) + initTree(mid+1, end, 2*N+1);
}

void update(int index, int diff){
    update(0, treeEnd, 1, index, diff);
}

void update(int start, int end, int N, int index, int diff){
    if(index > end || index < start){
        return;
    }
    tree[N] += diff;
    if(start == end){
        return;
    }
    int mid = (start + end)/2;
    update(start, mid, 2*N, index, diff);
    update(mid+1, end, 2*N+1, index, diff);
}

int sum(int left, int right){
    return sum(0,treeEnd, 1, left, right);
}

int sum(int start, int end, int N, int left, int right) {
    if(right < start || left > end){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[N];
    }

    int mid = (start + end)/2;
    return sum(start, mid, 2*N, left,right) + sum(mid+1, end,2*N+1, left, right);

}
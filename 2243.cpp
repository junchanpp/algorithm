#include <iostream>
#include <vector>
#define CANDY_MAX 1000000

using namespace std;

vector<int> candys;
int N;

int getIndex(int rank);
int getIndex(int start, int end, int node, int rank);
void update(int index, int diff);
void update(int start, int end, int node, int index, int diff);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    candys.assign(4*CANDY_MAX+1, 0);
    cin >> N;

    vector<int> answers;
    for(int i = 0 ; i < N; i++){
        int type;
        cin >> type;
        if(type == 1){
            int rank;
            cin >> rank;
            int index = getIndex(rank);
            answers.push_back(index);
            update(index, -1);
        }else {
            int index, count;
            cin >> index >> count;
            update(index, count);
        }
    }

    for(int i = 0 ; i < answers.size(); i++){
        cout << answers[i] << '\n';
    }

    return 0;
}

int getIndex(int rank){
    return getIndex(1, CANDY_MAX, 1, rank);
}

int getIndex(int start, int end, int node, int rank){
    if(start == end){
        return start;
    }
    int mid = (start + end)/2;
    if(candys[2*node] >= rank){
        return getIndex(start, mid, 2*node, rank);
    } else {
        return getIndex(mid+1, end, 2*node+1, rank - candys[2*node]);
    }
}


void update(int index, int diff){
    update(1, CANDY_MAX, 1, index, diff);
}

void update(int start, int end, int node, int index, int diff){
    if(index < start || index > end){
        return;
    }
    candys[node] += diff;
    if(start == end){
        return;
    }
    int mid = (start+end)/2;
    update(start, mid, node * 2, index, diff);
    update(mid+1, end, node * 2 + 1, index, diff);
}
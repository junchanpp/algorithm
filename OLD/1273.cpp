#include <iostream>
#include <vector>

using namespace std;
int maxHeight;
vector<int> heightScores;
vector<int> shootHeights;

void updateHeightScore(int left, int right, int diff);//left~right까지 diff update
void updateHeightScore(int start, int end,int N, int left, int right, int diff);

void initShootHeights();
int initShootHeights(int start, int end, int N);
int getScoreAndShoot(int rank);
int getScoreAndShoot(int start, int end, int N, int rank);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N;
    vector<int> blacks(N,0);
    vector<int> grays(N,0);
    vector<int> whites(N,0);
    for(int i = 0; i <N; i++){
        cin >> blacks[i];
    }
    for(int i = 0; i <N; i++){
        cin >> grays[i];
    }
    for(int i = 0; i <N; i++){
        cin >> whites[i];
    }
    maxHeight = 1;
    for(int i = 0; i < N; i++){
        if(maxHeight < blacks[i] + grays[i] + whites[i]){
            maxHeight = blacks[i] + grays[i] + whites[i];
        }
    }
    
    heightScores.assign(maxHeight+1,0);
    shootHeights.assign(4*maxHeight,0);

    initShootHeights();
    
    heightScores[1] = N;
    for(int i = 0 ; i < N; i++){
        // heightScores[1] += 1;
        heightScores[blacks[i]+1] += 1;
        heightScores[blacks[i]+grays[i]+1] += 3;
        heightScores[blacks[i]+grays[i]+whites[i]+1] -= 5;
    }
    for(int i = 1; i <=maxHeight; i++){
        heightScores[i] += heightScores[i-1];
    }

    cin >> M;

    vector<long long> answers;
    for(int i =0; i < M; i++){
        int shootHeight;
        cin >> shootHeight;

        int score = shootHeight > maxHeight ? 0 : getScoreAndShoot(shootHeight);

        answers.push_back(score);
    }

    for(int i = 0 ; i < answers.size(); i++){
        cout << answers[i] << '\n';
    }
}

void initShootHeights(){
    initShootHeights(1, maxHeight, 1);
}

int initShootHeights(int start, int end, int N){
    if(start== end){
        return shootHeights[N] = 1;
    }
    int mid = (start+end) / 2;
    return shootHeights[N] = initShootHeights(start,mid, 2*N) + initShootHeights(mid+1,end, 2*N+1);
}

int getScoreAndShoot(int rank){
    return getScoreAndShoot(1, maxHeight, 1, rank);
}


int getScoreAndShoot(int start, int end, int N, int rank) {
    vector<int> indexList;
    indexList.push_back(N);
    while (start != end) {
        int mid = (start + end) / 2;
        if (shootHeights[2 * N] >= rank) {
            end = mid;
            N *= 2;
        } else {
            start = mid + 1;
            rank -= shootHeights[2 * N];
            N = 2 * N + 1;
        }
        indexList.push_back(N);
    }
    if (heightScores[start] != 0) {
        for(int i = 0 ; i < indexList.size(); i++){
            shootHeights[indexList[i]]--;
        }
    }
    return heightScores[start];
}
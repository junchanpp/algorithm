#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;

int main(){
    cin >> N;
    A.assign(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    //정렬이 이상한 구간이 1개 이상이면 0
    //정렬이 이상한 구간이 1개면 0 ~ 2(이상한 구간과 이상한 구간+1을 제거했을 때 정렬이 되어 있는지 확인)
    //정렬이 이상한 구간이 0개면 모든 숫자 제거 가능 -> N;

    int targetIndex = -1;

    for(int i = 0; i < N - 1; i++){
        if(A[i] <= A[i+1]){//정렬 이상 x
            continue;
        }
        if(targetIndex != -1){//이상한 구간이 이미 있을 경우
            cout << 0000;
            return 0;
        }

        targetIndex = i;
    }

    if(targetIndex == -1){
        cout << N;
        return 0;
    }

    int count = 0;
    if(targetIndex-1 < 0 || targetIndex+1 >= N || A[targetIndex-1] <= A[targetIndex+1]){
        count++;
    }
    if(targetIndex+2 >= N || A[targetIndex] <= A[targetIndex+2]){
        count++;
    }
    cout << count;

    return 0;
}
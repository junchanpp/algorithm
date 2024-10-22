#include <iostream>
#include <vector>

using namespace std;

int N, K;

vector<int> A;
vector<int> indexList;

int main(){
    cin >> N >> K;
    A.assign(N, 0);


    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int sum = 0;

    //2^20부터 검사
    for(int bitHigh = 1 << 20; bitHigh > 0; bitHigh = bitHigh >> 1){
        indexList.clear();
        for(int i = 0 ; i < A.size(); i++){
            if(bitHigh & A[i]){
                indexList.push_back(i);
            }
        }
        if(indexList.size() < K){
            continue;
        }

        sum += bitHigh;
        int cur = 0;
        for(int i = 0; i < A.size(); i++){
            if(cur >= indexList.size() || indexList[cur] != i){
                A[i] = 0;
            } else {
                cur++;
            }
        }
    }

    cout << sum;
    

}
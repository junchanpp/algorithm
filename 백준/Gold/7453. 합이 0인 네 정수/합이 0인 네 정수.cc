#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;

vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    A.assign(N, 0);
    B.assign(N, 0);
    C.assign(N, 0);
    D.assign(N, 0);

    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> targetNumbers;

    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            targetNumbers.push_back(A[i] + B[j]);
        }
    }

    long long count = 0;
    sort(targetNumbers.begin(),targetNumbers.end());

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int sum = (C[i] + D[j]) * -1;
            count += distance(lower_bound(targetNumbers.begin(), targetNumbers.end(), sum), upper_bound(targetNumbers.begin(), targetNumbers.end(), sum));
            
        }
    }

    cout << count;


}

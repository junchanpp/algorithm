#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<long long> A,T,Q;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    A.assign(N,0);
    T.assign(M,0);
    Q.assign(M,0);

    for(int i = 0; i < N; i++){
        cin >>A[i];
    }

    for(int i = 0; i < M; i++){
        cin >> T[i] >> Q[i];//오름차순
    }

    sort(A.rbegin(), A.rend());

    long long index = 0;
    long long day = 0;
    long long nowQuality = 0;

    for(int i = 0 ; i < M; i++){
        day = T[i];
        long long requiredQuality = Q[i];
        while(nowQuality < requiredQuality){
            if(index >= N){
                cout << -1;
                return 0;
            }
            nowQuality += A[index++] + day;
        }
    }
    while(index < N){
        nowQuality += A[index++] + day;
    }

    cout << nowQuality;


}
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long solve(int N, vector<long long> P);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }

    cout << solve(N, P) << endl;
}


long long solve(int N, vector<long long> p){
    long long sum = 0;

    for(int i = 0; i < N; i++){
        sum += p[i];
    }
    vector<long long> arr(N);//순방향 연속합
    vector<long long> rarr(N);//역방향 연속합

    vector<long long> maxNumbers(N);//순방향 연속합의 최댓값
    vector<long long> rmaxNumbers(N);//역방향 연속합의 최댓값

    arr[0] = p[0];
    maxNumbers[0] = p[0];
    for(int i = 1 ; i < N; i++){
        arr[i] = max(arr[i-1]+ p[i], p[i]);
        maxNumbers[i] = max(arr[i], maxNumbers[i-1]);
    }

    rarr[N-1] = p[N-1];
    rmaxNumbers[N-1] = p[N-1];
    for(int i = N-2 ; i >= 0; i--){
        rarr[i] = max(rarr[i+1]+ p[i], p[i]);
        rmaxNumbers[i] = max(rarr[i], rmaxNumbers[i+1]);
    }

    long long result = sum;

    for(int i = 0; i <= N; i++){
        result = max(result, sum + (i == 0 ? 0 : maxNumbers[i-1]) + (i == N ? 0 : rmaxNumbers[i]));
    }

    return result;
}
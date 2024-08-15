#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long S, C;
vector<long long> L;
long long sum = 0;

bool check(long long num){
    long long result = 0;
    for(int i = 0 ; i < S; i++){
        result += L[i] / num;
    }
    return result >= C;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> S >> C;
    L.assign(S, 0);
    for(int i = 0; i < S; i++){
        cin >> L[i];
        sum += L[i];
    }

    sort(L.begin(), L.end());

    long long hi = 1000000000;
    long long lo = 1;
    long long target = 0;
    while(lo <= hi){
        long long mid = (lo+hi)/2;
        if(check(mid)){//check(): [mid, S-1]까지 C개 이상이면 true
            lo = mid + 1;
            target = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << sum - (target * C);

}
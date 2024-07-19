#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b);

int main(){
    int N;
    cin >> N;
    
    vector<int> inputs(N,0);
    long long totalMul = 1;
    
    for(int i = 0; i < N; i++){
        cin >> inputs[i];
        totalMul *= inputs[i];
    }

    long long childNum = 0;
    long long parrentNum = totalMul;

    for(int i = 0; i < N; i++){
        childNum += totalMul/inputs[i];
    }

    cout << parrentNum/gcd(childNum,parrentNum) << '/' << childNum/gcd(childNum,parrentNum);
    
}


long long gcd(long long a, long long b){
    long long c;
    while(b!=0){
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}
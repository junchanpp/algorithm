#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int M, N;

int main(){
    cin >> M >> N;
    if(M == 0 && N == 0){
        cout << 0;
        return 0;
    }

    if(gcd(abs(M),abs(N)) == 1){
        cout << 1;
    }else {
        cout << 2;
    }
    
}
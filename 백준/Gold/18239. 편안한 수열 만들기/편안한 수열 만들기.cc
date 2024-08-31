#include <iostream>

using namespace std;

int N, K;

int main(){
    cin >> N >> K;

    if(N == 2){
        cout << "YES\n";
        cout << "swap 1 2\n";
        cout << "swap 1 2\n";
        cout << "swap 1 2\n";
        cout << "swap 1 2\n";
        cout << "swap 1 2\n";
    } else if(N == 3){
        cout << "NO\n";
    } else if(N== 4 && (K == 1 || K == N-1)){
        if(K == 1){
            cout << "YES\n";
            cout << "swap 1 " << N - 1 << '\n';
            cout << "reverse 1 2\n";
            cout << "reverse 3 4\n";
            cout << "reverse 1 " << N << '\n';
            cout << "reverse 1 " << N << '\n';
        }else {
        cout << "YES\n";
        cout << "swap 2 " << N << '\n';
        cout << "reverse 1 2\n";
        cout << "reverse 3 4\n";
        cout << "reverse 1 " << N << '\n';
        cout << "reverse 1 " << N << '\n';
            
        }
    } else if(K == 1){
        cout << "YES\n";
        cout << "swap 2 " << N << '\n';
        cout << "reverse 3 " << N-1 << '\n';
        cout << "reverse 1 " << N << '\n';
        cout << "reverse 1 " << N << '\n';
        cout << "reverse 1 " << N << '\n';
    } else if(K == N - 1){
        cout << "YES\n";
        cout << "swap 1 " << N-1 << '\n';
        cout << "reverse 2 " << N-2 << '\n';
        cout << "reverse 1 " << N << '\n';
        cout << "reverse 1 " << N << '\n';
        cout << "reverse 1 " << N << '\n';
    } else {
        cout << "YES\n";
        cout << "reverse 1 " << K << '\n';
        cout << "reverse " << (K+1) << ' ' << N << '\n';
        cout << "reverse 1 " << N << '\n';
        cout << "reverse 1 " << N << '\n';
        cout << "reverse 1 " << N << '\n';
    }
}
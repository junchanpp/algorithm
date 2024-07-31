#include <iostream>


using namespace std;

int N, K;

int main(){
    cin >> N >> K;
    for(int i = 1; i < N; i++){
        if((N-i) * i < K){
            continue;
        }
        int length = 0;

        while(K != 0 || i != 0){
            while(i <= K){
                cout << 'A';
                K -= i;
                length++;
            }
            cout << 'B';
            length++;
            i--;
        }
        while(length < N){
            cout << 'A';
            length++;
        }
        return 0;
    }

    cout << -1;
}
#include <iostream>

using namespace std;

bool isStrange(int num){
    int a = 0;
    int numCopy = num;
    while(numCopy != 0){
        a += numCopy % 10;
        numCopy /= 10;
    }
    return (num % a == 0);
}

int main(){
    long long N;
    cin >> N;

    int count = 0;

    for(int i = 1 ; i <= N; i++){
        if(isStrange(i)){
            count++;
        }
    }

    cout << count;
}
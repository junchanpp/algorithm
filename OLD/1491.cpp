#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int roundTripN = M <= N ? M : N;
    int roundTripM = M <= N ? M-1 : N;

    int firstAnswer;
    if(roundTripN % 2 == 1){
        firstAnswer = N - roundTripN/2 - 1;
    }else {
        firstAnswer = 0 + (roundTripN-1)/2;
    }
    
    int secondAnswer;
    if(roundTripM % 2 == 1){
        secondAnswer = M - roundTripM/2 - 1;
    }else {
        secondAnswer = 0 + roundTripM/2;
    }

    cout << firstAnswer << " " << secondAnswer;
}
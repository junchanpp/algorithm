#include <iostream>
#include <cmath>
using namespace std;
bool arr[10000001] = {0,};// 1이면 소수가 아님
int main(){
    long long A, B;
    cin >> A >> B;


    arr[0] = 1;
    arr[1] = 1;

    long long maxIndex = 10000;
    long long maxIndex2 = 10000000;
    for(long long i = 2; i <= maxIndex; i++){
        if(arr[i] != 0){
            continue;
        }
        for(long long j = i+i; j <= maxIndex2; j+=i){
            arr[j] = 1;
        }
    }

    long long answer = 0;
    for(long long i = 2; i <= maxIndex2; i++){
        if(arr[i] != 0){
            continue;
        }

        for(long long j = i*i; j <= B; j*=i){
            if(j >= A){
                answer++;
            }
            if(j > B/i){
                break;
            }
        }
    }

    cout << answer;
}
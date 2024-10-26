#include <iostream>
#include <vector>
#define BIT_MAX 21

using namespace std;

int N;

vector<int> bitZeroCount;
vector<int> bitOneCount;

int main(){
    cin >> N;
    bitZeroCount.assign(BIT_MAX, 0);
    bitOneCount.assign(BIT_MAX, 0);
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;

        int index = 0;
        while(index < BIT_MAX){
            if(input % 2 == 0){
                bitZeroCount[index]++;
            } else {
                bitOneCount[index]++;
            }
            input = input >> 1;
            index++;
        }
    }

    long long result = 0;

    for(int i = 0; i < BIT_MAX; i++){
        result += (long long)(1 << i) * bitZeroCount[i] * bitOneCount[i];
    }

    cout << result;

    
}
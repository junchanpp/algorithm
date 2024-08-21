#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, K;
vector<int> inputs;

int main(){
    cin >> N >> K;
    inputs.resize(N);


    for(int i = 0 ; i < N; i++){
        cin >> inputs[i];
        --inputs[i];
    }

    int count = 0;
    int answer = INT_MAX;

    int i = 0;
    int j = 0;
    
    while(j < N){
        while(count < K && j < N){
            count += inputs[j++] ? 0 : 1;
        }
        if(count < K && j == N){
            break;
        }
        j--;
        while(inputs[i]){
            i++;
        }
        if(answer > j - i + 1){
            answer = j - i + 1;
        }
        i++;
        j++;
        count--;
    }

    cout << (answer == INT_MAX ? -1 : answer);

}
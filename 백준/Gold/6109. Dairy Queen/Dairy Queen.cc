#include <iostream>
#include <vector>

using namespace std;

int N, C;
vector<int> inputs;

int solve(int i, int amount){
    int count = 0;
    if(amount == 0) return 1;
    if(i == C - 1){
        return amount % inputs[i] == 0;
    }

    while(amount >= 0){
        count += solve(i + 1, amount);
        amount -= inputs[i];
    }

    return count;
}

int main(){
    cin >> N >> C;
    inputs.assign(C, 0);

    for(int i = 0 ; i < C; i++){
        cin >> inputs[i];
    }

    
    cout << solve(0, N);
}
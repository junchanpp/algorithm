#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> S;


int solve(vector<int> targetNumbers){
    int answer = 0;
    int count = 0;
    for(int i = 0; i < N; i++){
        if(targetNumbers[0] == S[i] || targetNumbers[1] == S[i]){
            count++;
            answer = max(answer, count);
        }else {
            count = 0;
        }
    }

    return answer;
}


int main(){
    cin >> N;
    S.assign(N, 0);
    for(int i = 0 ; i < N; i++){
        cin >> S[i];
    }

    vector<int> arr;

    for(int i = 0; i < 2; i++){
        arr.push_back(1);
    }
    for(int i = 2; i < 9; i++){
        arr.push_back(0);
    }
    sort(arr.begin(), arr.end());

    int answer = 0;

    do{
        int index = 0;
        vector<int> targetNumbers(2,0);

        for(int i = 0; i < arr.size(); i++){
            if(index == 2){
                break;
            }
            if(arr[i]){
                targetNumbers[index] = i+1;
                index++;
            }
        }

        answer = max(answer, solve(targetNumbers));

    }while(next_permutation(arr.begin(), arr.end()));


    cout << answer;
    
}
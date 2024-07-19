#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }

    int answer = 0;
    int left = 0;
    int right = 0;

    for(int i = 0; i < N; i++){
        if(arr[i] == 1){
            left = left + 1;
            right = max(0, right -1);
        } else {
            left = max(0, left -1);
            right = right +1;
        }
        answer = max(answer, max(left, right));
    }

    cout << answer;
}
#include <iostream>
#include <vector>

using namespace std;

int solution(int N,vector<int> arr);

int main(){
    int N;
    cin >> N;
    vector<int> arr(N);

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int answer =  solution(N, arr);

    cout << answer;

    return 0;
}

int solution(int N,vector<int> arr){
    for(int i = 0; i < N; i)
}
#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<int> Fs;

int main(){
    cin >> T;
    cin >> N;
    
    int sum = 0;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        sum += temp;
    }

    if(T > sum){
        cout << "Padaeng_i Cry";
    }else {
        cout << "Padaeng_i Happy";
    }
}
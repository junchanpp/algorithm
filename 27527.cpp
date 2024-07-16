#include <iostream>
#include <vector>

using namespace std;

int N,M;

int main(){
    cin >> N >> M;
    vector<int> inputs(N,0);
    vector<int> arr(1000001,0);
    int boundedCount = (9*M)/10 + ((9*M)% 10 > 0 ? 1 : 0);
    
    for(int i = 0 ; i < N ; i++){
        cin >> inputs[i];
    }
    for(int i = 0 ; i < M; i++){
        if(++arr[inputs[i]] >= boundedCount){
            cout << "YES";
            return 0;
        }
    }

    for(int i = 0 ; i < N-M; i++){
        arr[inputs[i]]--;
        if(++arr[inputs[i+M]] >= boundedCount){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;

}
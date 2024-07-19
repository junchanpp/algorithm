#include <iostream>
#include <vector>

using namespace std;

vector<long long> factorials;

int endNum;

void initFactorials(long long N){
    long long lastResult = 1; // 0! 미리 넣어두기
    factorials.push_back(lastResult);
    
    int i;
    for(i= 1; N >= lastResult; i++){
        lastResult *= i;
        factorials.push_back(lastResult);
    }

    endNum = i;
}

int main(){
    long long N;
    cin >> N;

    initFactorials(N);

    vector<long long> results;
    

    for(int i = 0 ; i < endNum; i++){
        int endIndex = results.size();

        if(factorials[i] == N){
            cout << "YES";
            return 0;
        }
        results.push_back(factorials[i]);
        for(int j = 0; j < endIndex; j++){
            long long result = results[j] + factorials[i];
            if(result == N){
                cout << "YES";
                return 0;
            }
            results.push_back(result);
        }
    }

    cout << "NO";
    return 0;


}


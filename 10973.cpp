#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;

    cin >> N;
    vector<int> inputs(N,0);

    for(int i = 0 ; i < N; i++){
        cin >> inputs[i];
    }

    vector<int> scanedInputs;

    for(int i = N-1; i >= 1; i--){
        scanedInputs.push_back(inputs[i]);
        if(inputs[i] > inputs[i-1]){
            continue;
        }
        //정답 추출
        int baseNum = inputs[i-1];
        int BigestNumOflessThanBaseNum= -1;
        for(int j = 0; j < scanedInputs.size(); j++){
            if(baseNum > scanedInputs[j] && BigestNumOflessThanBaseNum < scanedInputs[j]){
                BigestNumOflessThanBaseNum = scanedInputs[j];
            }
        }
        scanedInputs.push_back(inputs[i-1]);
        sort(scanedInputs.rbegin(), scanedInputs.rend());

        for(int j = 0; j < i-1; j++){
            cout << inputs[j] << " ";
        }

        cout << BigestNumOflessThanBaseNum << " ";


        for(int j = 0; j < scanedInputs.size(); j++){
            if(scanedInputs[j] == BigestNumOflessThanBaseNum){
                continue;
            }
            cout << scanedInputs[j] << " ";
        }

        return 0;
    }

    cout << -1;
}
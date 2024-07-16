#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;

    string names[9] = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
    int max[9] = {0,};

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < N; j++){
            int num;
            cin >> num;
            if(max[i] < num){
                max[i] = num;
            }
        }
    }

    int totalMaxIndex = 0;
    for(int j = 1; j < 9; j++){
        if(max[totalMaxIndex] < max[j]){
            totalMaxIndex = j;
        }
    }

    cout << names[totalMaxIndex];
}
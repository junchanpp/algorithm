#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;



int main(){
    int N, K;
    cin >> N >> K;

    vector<pair<int, int> > inputs(N,make_pair(0,0));
    vector<int> room(K,0);

    for(int i = 0; i < N; i++){
        cin >> inputs[i].first >> inputs[i].second;
    }

    sort(inputs.begin(),inputs.end());

    int count = 0;

    for(int i = 0; i < N; i++){
        bool isInserted = false;
        for(int j = 0; j < K; j++){
            if(room[j] < inputs[i].first){
                room[j] = inputs[i].second;
                count++;
                isInserted = true;
                break;
            }
        }
        if(isInserted){
            continue;
        }

        int maxIndex = 0;
        for(int j = 1; j < K; j++){
            if(room[maxIndex] < room[j]){
                maxIndex = j;
            }
        }
        if(room[maxIndex] > inputs[i].second){
            room[maxIndex] = inputs[i].second;
        }
    }

    cout << count;


}
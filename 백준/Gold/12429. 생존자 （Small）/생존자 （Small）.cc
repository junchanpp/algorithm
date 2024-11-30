#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int T, N;
vector<int> answers;

int main(){
    cin >> T;
    while(T--){
        vector<pair<int, int> > inputs;
        cin >> N;

        for(int i = 0 ; i < N; i++){
            int P, S;
            cin >> P >> S;
            inputs.push_back(make_pair((S + P), S));
        }

        sort(inputs.begin(), inputs.end());

        vector<bool> times;
        times.assign(201, 0);
        times[0] = 1;

        int answer = 0;
        for(int i = 0; i < inputs.size(); i++){
            int end = inputs[i].first - inputs[i].second;
            int eatTime = inputs[i].second;
            for(int i = end; i >= 0; i--){
                if(times[i]){
                    times[i+eatTime]= 1;
                    answer = max(answer, i+ eatTime);
                }
            }
        }
        answers.push_back(answer);

    }

    for(int i = 0; i < answers.size(); i++){
        cout << "Case #" << (i+1) << ": " << answers[i] << '\n';
    }
    
}
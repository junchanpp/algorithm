#include <iostream>
#include <vector>
#include <utility>

using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    int K;
    cin >> N >> K;
    vector<pair<int,int> > inputs(K);
    vector<int> answers(K);

    for(int i = 0; i <K;i++){
        cin >> inputs[i].first >> inputs[i].second;
    }

    int mid = (N+1)/2;

    for(int i = 0 ; i < K; i++){
        int first = inputs[i].first;
        int second = inputs[i].second;

        first = mid < first ? N - first : first;
        second = mid < second ? N - second : second;
        int focusColor = (first < second ?  first : second) % 3;

        answers.push_back(focusColor);
    }

    for(int i = 0 ; i < K ; i++){
        cout << answers[i];
    }


}
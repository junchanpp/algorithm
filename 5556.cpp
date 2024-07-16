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
    vector<int> answers;

    for(int i = 0; i < K;i++){
        cin >> inputs[i].first >> inputs[i].second;
    }

    int mid = (N+1)/2;

    for(int i = 0 ; i < K; i++){
        int first = inputs[i].first;
        int second = inputs[i].second;

        first = mid < first ? N - first + 1 : first;
        second = mid < second ? N - second + 1 : second;

        int focusColor = (first < second ?  first : second) % 3;
        focusColor = focusColor == 0 ? 3 : focusColor;

        answers.push_back(focusColor);
    }

    for(int i = 0 ; i < K ; i++){
        cout << answers[i] << '\n';
    }


}
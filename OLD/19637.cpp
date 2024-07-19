#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int N, M;
map<int, string> tags;
vector<int> answers;

int getTagIndex(int score){
    return tags.lower_bound(score)->first;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        string tag;
        int score;
        cin >> tag >> score;
        if(tags.find(score) != tags.end()){
            continue;
        }
        tags.insert(make_pair(score, tag));
    }



    for(int i =0; i < M; i++){
        int score;
        cin >> score;
        answers.push_back(getTagIndex(score));
    }

    for(int i = 0; i < M; i++){
        cout << tags.find(answers[i])->second << '\n';
    }



}
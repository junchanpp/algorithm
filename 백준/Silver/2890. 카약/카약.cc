#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int R, C;
vector<int> start;//값이 클수록 등수+1

int main(){
    cin >> R >> C;
    start.assign(10, 0);
    for(int i = 0 ; i < R; i++){
        string s;
        cin >> s;
        for(int j = 1; j < C - 1; j++){
            if(s[j] != '.'){
                start[s[j]-'0'] = j;
                break;
            }
        }
    }
    vector<pair<int, int> > result;
    for(int i = 1; i < 10; i++){
        result.push_back(make_pair(start[i], i));
    }
    sort(result.rbegin(), result.rend());

    int answer = 1;
    int lastNum = result[0].first;
    vector<int> answers(10,0);
    for(int i = 0; i < 9; i++){
        if(lastNum != result[i].first){
            answer++;
            lastNum = result[i].first;
        }
        answers[result[i].second] = answer;
    }
    for(int i = 1; i < 10; i++){
        cout << answers[i] << '\n';
    }
}
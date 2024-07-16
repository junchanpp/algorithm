#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);



    int N = 0;
    cin >> N;


    map<int, set<int> > difficulties;
    unordered_map<int, int> problems;
    vector<int> answers;

    for(int i = 0; i < N; i++){
        int P,L;
        cin >> P >> L;
        if(difficulties.find(L) == difficulties.end()){
            difficulties.insert(make_pair(L, set<int>()));
        }
        (difficulties.find(L)->second).insert(P);

        problems.insert(make_pair(P, L));
    }


    cin >> N;


    for(int i = 0 ; i < N; i++){
        string s;
        cin >> s;
        if(s[0] =='r'){
            int x;
            cin >> x;
            if(x == 1){
                answers.push_back(*(difficulties.rbegin()->second).rbegin());
            } else {
                answers.push_back(*(difficulties.begin()->second).begin());
            }
        }else if(s[0] =='a'){
            int P,L;
            cin >> P >> L;
            if(difficulties.find(L) == difficulties.end()){
                difficulties.insert(make_pair(L, set<int>()));
            }
            (difficulties.find(L)->second).insert(P);

            problems.insert(make_pair(P, L));
        } else {
            int P;
            cin >> P;
            int L = (problems.find(P))->second;
            (difficulties.find(L)->second).erase(difficulties.find(L)->second.find(P));
            if((difficulties.find(L)->second).empty()){
                difficulties.erase(difficulties.find(L));
            }
            problems.erase(problems.find(P));
        }
    }
    for(int i = 0 ; i < answers.size(); i++){
        cout << answers[i] << '\n';
    }
}
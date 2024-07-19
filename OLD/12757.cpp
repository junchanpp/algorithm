#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;
int N, M, K;
map<int,int> inputs;
map<int,int> rinputs;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;

    for(int i = 0 ; i < N; i++){
        int key, value;
        cin >> key >> value;
        inputs.insert(make_pair(key,value));
        rinputs.insert(make_pair(-key,value));
    }
    inputs.insert(make_pair(INT_MAX, 0));//lower_bound 할 시 end()가 나오지 않게끔 설정
    rinputs.insert(make_pair(INT_MAX,0));

    vector<int> answers;
    for(int i = 0 ; i < M; i++){
        int type;
        cin >> type;
        if(type == 1){
            int key, value;
            cin >> key >> value;
            inputs.insert(make_pair(key,value));
            rinputs.insert(make_pair(-key,value));
        } else if(type == 2){
            int key, value;
            cin >> key >> value;
            map<int,int>::iterator iter = inputs.lower_bound(key);
            map<int,int>::iterator riter = rinputs.lower_bound(-key);
            int iterDiff = abs(key - iter->first);
            int riterDiff = abs(-riter->first - key);
            if(iter->first == -(riter->first)){
                iter->second = value;
                riter->second = value;
            } else if(iterDiff == riterDiff){
                continue;
            } else if(iterDiff < riterDiff && iterDiff <= K){
                iter->second = value;
                rinputs[-(iter->first)] = value;
            } else if(riterDiff < iterDiff && riterDiff <= K){
                riter->second = value;
                inputs[-(riter->first)] = value;
            }
            
        } else {
            int key;
            cin >> key;11657
            map<int,int>::iterator iter = inputs.lower_bound(key);
            map<int,int>::iterator riter = rinputs.lower_bound(-key);
            int iterDiff = abs(key - iter->first);
            int riterDiff = abs(-riter->first - key);
            if(iter->first == -(riter->first)){
                answers.push_back(iter->second);
            } else if(iterDiff == riterDiff && iterDiff <= K){
                answers.push_back(-2);
            } else if(iterDiff < riterDiff && iterDiff <= K){
                answers.push_back(iter->second);
            } else if(riterDiff < iterDiff && riterDiff <= K){
                answers.push_back(riter->second);
            } else {
                answers.push_back(-1);
            }
        }
    }
    for(int i = 0 ; i < answers.size(); i++){
        if(answers[i] == -2){
            cout << "?\n";
        } else {
            cout << answers[i] <<'\n';
        }
    }
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main(){
    string s1, s2;

    cin >> s1 >> s2;

    int length = max(s1.size(), s2.size());
    
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    string answer;

    int roundNumber = 0;
    
    for(int i = 0 ; i < length; i++){
        int subResult = roundNumber;
        
        if(s1.size() > i){
            subResult += s1[i] - '0';
        }
        if(s2.size() > i){
            subResult += s2[i] - '0';
        }

        answer.push_back((subResult % 10) + '0');

        roundNumber = subResult / 10;
    }

    if(roundNumber != 0){
        answer.push_back(roundNumber + '0');
    }

    reverse(answer.begin(), answer.end());

    cout << answer << '\n';
}
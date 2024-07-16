#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    vector<pair<int,int> > answers;

    answers.push_back(make_pair(12,1600));
    answers.push_back(make_pair(11,894));
    answers.push_back(make_pair(11,1327));
    answers.push_back(make_pair(10,1311));
    answers.push_back(make_pair(9,1004));
    answers.push_back(make_pair(9,1178));
    answers.push_back(make_pair(9,1357));
    answers.push_back(make_pair(8,837));
    answers.push_back(make_pair(7,1055));
    answers.push_back(make_pair(6,556));
    answers.push_back(make_pair(6,773));

    int N;
    cin >> N;
    cout << answers[N-1].first << " " << answers[N-1].second; 

}
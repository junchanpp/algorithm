#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> answers;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        answers.push_back(n % 2 == 0 ? 1 : 0);
    }

    for(int i = 0; i < answers.size(); i++){
        cout << (answers[i] ? 'A' : 'B') << '\n';
    }

    return 0;
}
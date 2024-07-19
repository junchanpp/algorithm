#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> answers;

    for(int i =0 ; i < N; i++){
        long long a, b;
        cin >> a >> b;
        answers.push_back((b-a+1)*(b+a)/2);
    }

    for(int i = 0 ; i < N; i++){
        cout << "Scenario #" << i+1 << ":\n"  << answers[i] << "\n\n";
    }
}
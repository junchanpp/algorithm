#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int solve(int n, vector<int> v);

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> inputs(n);
    cout << s;
    for(int i = 0 ; i < n; i++){
        cin >> inputs[i];
    }

    cout << solve(n, inputs);
}

int solve(int n, vector<int> inputs){
    int sum = 0;
    int result = INT_MIN;
    for(int i = 0 ; i < n; i++){
        sum = max(sum + inputs[i], inputs[i]);
        if(result < sum){result = sum;}
    }
    return result;
}
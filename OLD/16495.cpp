#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    long long mul = 1;
    long long sum = 0;
    for(int i = s.size()-1; i >= 0; i--){
        sum += mul*(s[i]-'A'+1);
        mul *= 26;
    }

    cout << sum;
}
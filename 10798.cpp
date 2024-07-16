#include <iostream>
#include <string>

using namespace std;

string s[5];

int main(){
    cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];

    for(int i = 0 ; i < 15; i++){
        for(int j = 0 ; j < 5; j++){
            if(s[j].size() > i){
                cout << s[j][i];
            }
        }
    }
}
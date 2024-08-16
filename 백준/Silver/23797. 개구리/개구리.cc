#include <iostream>
#include <string>

using namespace std;

string S;
int nextKCount = 0;
int nextPCount = 0;

int main(){
     cin >> S;
     for(int i = 0; i < S.size(); i++){
        if(S[i] == 'K'){
            if(nextKCount == 0){
                nextPCount++;
            }else {
                nextKCount--;
                nextPCount++;
            }
        }else {
            if(nextPCount == 0){
                nextKCount++;
            }else {
                nextPCount--;
                nextKCount++;
            }
        }
     }

     cout << nextKCount + nextPCount;

}
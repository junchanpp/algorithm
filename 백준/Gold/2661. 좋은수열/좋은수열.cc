#include <iostream>
#include <string>

using namespace std;

int N;
bool isCompleted;
bool isOk(string s){
    for(int i = 1 ; i <= s.size()/2; i++){
        string s1 = s.substr(s.size()-i-i,i);
        string s2 = s.substr(s.size()-i,i);
        if(s1 == s2){
            return false;
        }
    }
    return true;
}
void solve(int count, string s){
    if(count == N){
        cout << s;
        isCompleted = true;
        return;
    }

    if(!isCompleted && isOk(s + "1")){
        solve(count+1, s + "1");

    }
    if(!isCompleted && isOk(s + "2")){
        solve(count+1, s + "2");
    }
    if(!isCompleted && isOk(s + "3")){
        solve(count+1, s + "3");
    }

    return;
}
int main(){
    cin >> N;
    isCompleted = false;
    solve(0, "");
}
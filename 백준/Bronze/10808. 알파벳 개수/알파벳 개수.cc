#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> arr('z'-'a'+1,0);
    for(int i = 0 ; i < s.size(); i++){
        arr[s[i]-'a']++;
    }
    for(int i = 0 ; i < arr.size(); i++){
        cout << arr[i] <<' ';
    }
    
}
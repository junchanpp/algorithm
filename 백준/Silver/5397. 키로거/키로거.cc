#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;

        vector<char> st;
        vector<char> temp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<'){
                if(st.empty()){
                    continue;
                }
                temp.push_back(st.back());
                st.pop_back();
            }else if(s[i] == '>'){
                if(temp.empty()){
                    continue;
                }
                st.push_back(temp.back());
                temp.pop_back();
            }else if(s[i] =='-'){
                if(st.empty()){
                    continue;
                }
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }
        while(!temp.empty()){
            st.push_back(temp.back());
            temp.pop_back();
        }
        for(int i = 0; i < st.size(); i++){
            cout << st[i]; 
        }cout << '\n';
    }
}
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;
string s[3];
int N;
vector<char> a(10,0);
vector<char> alphabet;
vector<int> alphabetToNum(26,0);

int parseToInt(string str){
    int n = 0;
    int result = 0;
    int size = str.length();
    while(n < size){
        result*=10;
        result+=alphabetToNum[str[n]-'A'];
        n++;
    }
    return result;
}
bool check(){
    return parseToInt(s[0])+parseToInt(s[1]) == parseToInt(s[2]);
}
bool solve(int index){
    if(N == index)return check();
    for(int i = 0; i< 10;i++){
        if(a[i]==0){
            a[i] = alphabet[index];
            alphabetToNum[alphabet[index]-'A'] = i;
            bool answer = solve(index+1);
            if(answer == true)return true;
            alphabetToNum[alphabet[index]-'A'] = 0;
            a[i] = 0;
        }
    }
    return false;
}

int main(){
    cin >> s[0] >> s[1] >> s[2];

    set<char> usingAlphabetSet;
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < s[i].length();j++){
            usingAlphabetSet.insert(s[i][j]);
        }
    }
    alphabet.resize(usingAlphabetSet.size());
    copy(usingAlphabetSet.begin(), usingAlphabetSet.end(),alphabet.begin());
    N = alphabet.size();

    bool answer = solve(0);

    cout << (answer ? "YES" : "NO");
}
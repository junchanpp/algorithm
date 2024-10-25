#include <iostream>
#include <vector>
#include <string>

using namespace std;
string numberList[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


string calc(string num1Str, string num2Str, string op){
    long long num1 = stoll(num1Str);
    long long num2 = stoll(num2Str);

    long long result = 0;
    if(op == "+"){
        result = num1 + num2;
    }else if(op == "-"){
        result = num1 - num2;
    }else if(op == "x"){
        result = num1 * num2;
    }else {
        result = num1 / num2;
    }

    return to_string(result);
}

void solve(string s){
    string subS;
    string num;
    vector<string> stringList;

    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == 'x' || s[i] == '/' || s[i] == '='){
            if(num == "" || subS != ""){
                cout << "Madness!" << '\n';
                return;
            }
            stringList.push_back(num);
            stringList.push_back(string(1,s[i]));
            num="";
            if(s[i] == '='){
                break;
            }
        } else {
            subS += s[i];
            for(int j = 0 ; j < 10; j++){
                if(subS == numberList[j]){
                    subS = "";
                    num +=('0'+j);
                    continue;
                }
            }
        }
    }

    for(int i = 0 ; i < stringList.size(); i++){
        cout << stringList[i];
    }cout <<'\n';

    string result = stringList[0];

    for(int i = 1; i < stringList.size()-1; i+=2){
        result = calc(result, stringList[i+1], stringList[i]);
    }

    for(int i = 0; i < result.size(); i++){
        bool isNum = false;
        for(int j = 0; j < 10; j++){
            if(j+'0' == result[i]){
                cout << numberList[j];
                isNum = true;
                break;
            }
        }
        if(!isNum){
            cout << result[i];
        }
    }
}

int main(){
    string s;
    cin >> s;

    solve(s);
}
//2023-02-17 19:33:00 start
//2023-02-18 22:01:00 end

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;

int n;
int coin[10];
vector<int> memo[51];
int m;

bool isAllZero(vector<int> v);
vector<int> getZeroList(int totalMoney);
int compare(string s1, string s2);
string getMaxNumber(vector<int> a);
vector<int> mergeVector(vector<int> a, vector<int> b);


int main(){
    cin >> n;

    for(int i =0 ; i< n; i++){
        cin >> coin[i];
    }


    cin >> m;

    for (int i = 0; i <= m; i++) {
        memo[i].push_back(0);
    }

    for(int i = 0 ; i <= m; i++){
        vector<int> max;
        for(int j = 1; j <= i/2;j++){
            if(compare(getMaxNumber(max), getMaxNumber(mergeVector(memo[j], memo[i-j])))< 0){max = mergeVector(memo[j],memo[i-j]); }
            if(compare(getMaxNumber(max), getMaxNumber(mergeVector(getZeroList(j),memo[i-j])))<0){max = mergeVector(getZeroList(j), memo[i-j]); }
            if(compare(getMaxNumber(max), getMaxNumber(mergeVector(memo[j],getZeroList(i-j))))<0){max = mergeVector(memo[j],getZeroList(i-j)); }
        }
        if(isAllZero(max)){
            max =vector<int>();
            max.push_back(0);
        }
        if(max.size() <= 1){
            int coinMax = -1;
            for(int j = 0; j < n;j++){
                if( i >= coin[j]){
                    coinMax =j;
                }
            }
            if(((max.size() == 1 && max[0] < coinMax) || max.size() == 0) && coinMax > -1) {
                max =  vector<int>();
                max.push_back(coinMax);
            }
        }
        if(i == m){
            cout << getMaxNumber(max) ;
            return 0;
        }
        memo[i] = max;
        
    }
}
bool isAllZero(vector<int> v){
    if(v.empty())return false;
    for(int i = 0; i < v.size(); i++){
        if(v[i]!=0){
            return false;
        }
    }
    return true;
}
vector<int> getZeroList(int totalMoney){
    vector<int> result;
    while(totalMoney> coin[0]){
        totalMoney = totalMoney -coin[0];
        result.push_back(0);
    }
    return result;
}

int compare(string s1, string s2) {
    if (s1.length() > s2.length()) return 1;
    else if (s1.length() < s2.length()) return -1;
    else return s1.compare(s2);
}

string getMaxNumber(vector<int> a) {
    string s;
    sort(a.begin(), a.end(), greater<int>());

    if (a.empty()) {
        return "";
    }
    else if (a[0] == 0) {
        return "0";
    }

    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
        s += to_string(*iter);
    }

    return s;
}

vector<int> mergeVector(vector<int> a, vector<int> b){

    vector<int> c;
    c.reserve(a.size()+b.size());
    c.insert(c.end(),a.begin(),a.end());
    c.insert(c.end(),b.begin(),b.end());
    return c;
}
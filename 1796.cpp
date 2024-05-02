#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

vector<vector<int> >indexList('z'-'a'+1);
int solve(int startPoint, char alphabet);
int memo['z'-'a'+1][51];//[i][j] <- i번째 문자열을 j번째 위치에서 시작할때

int main(){
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size(); i++){
        indexList[s[i]-'a'].push_back(i);
    }
    for(int i = 0 ; i < 'z'-'a'+1; i++){
        for(int j = 0 ; j < 51; j++){
            memo[i][j] = -1;
        }
    }
    cout<< s.size() + solve(0, 'a');
}


int calcDistance(int startPoint, char alphabet, int endPoint){
    int lowValue = indexList[alphabet-'a'][0];
    int highValue = indexList[alphabet-'a'][indexList[alphabet-'a'].size()-1];

    int start = min(startPoint, endPoint);
    int end = max(startPoint, endPoint);

    return (highValue - lowValue) + (abs(lowValue - start) + abs(highValue - end));
}

int solve(int startPoint, char alphabet){
    if(alphabet > 'z'){
        return 0;
    }
    if(memo[alphabet-'a'][startPoint] != -1){
        return memo[alphabet-'a'][startPoint];
    }
    while(alphabet <= 'z' && indexList[alphabet-'a'].size() == 0){
        alphabet++;
    }
    if(alphabet > 'z'){
        return 0;
    }
    int minValue = INT_MAX;
    for(int i = 0 ; i < indexList[alphabet-'a'].size(); i++){
        int distance = calcDistance(startPoint, alphabet, indexList[alphabet-'a'][i]);
        distance += solve(indexList[alphabet-'a'][i], alphabet+1);
        if(minValue > distance){
            minValue = distance;
        }
    }

    return memo[alphabet-'a'][startPoint] = minValue;
}
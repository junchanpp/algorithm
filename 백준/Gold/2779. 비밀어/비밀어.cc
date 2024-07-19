#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <map>
#include <queue>
using namespace std;

//word의 최대 길이 50, N 최대 50
map<char, int> countChar(string word);
int solve(int index);


vector<int> dp;
vector<map<char,int> > wordMap;

int N;
vector<string> words;
string subjectWord;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;

    while(T--){
        cin >> subjectWord;

        dp.assign(subjectWord.size(),INT_MAX);// N자리 이후 만드는데에 사용되는 비용
        wordMap.clear();

        cin >> N;
        words.clear();
        words.assign(N,"");

        for(int i = 0 ; i < N; i++){
            cin >> words[i];
        }


        for(int i = 0 ; i < words.size(); i++){
            map<char,int> countMap = countChar(words[i]);

            wordMap.push_back(countMap);
        }


        cout << solve(0) << '\n';
    }
}


map<char, int> countChar(string word){
    map<char, int> countMap;
    for(int i = 0 ; i < word.size(); i++){
        if(countMap.find((char)word[i]) != countMap.end()){
            countMap.find((char)word[i])->second++;
        } else {
            countMap.insert(make_pair((char)word[i],1));
        }
    }

    return countMap;
}

bool isIncluded(int start, int wordIndex){
    string word = words[wordIndex];
    map<char,int> countMap = wordMap[wordIndex];
    int size = word.size();

    for(int i = start; i < start+size;i++){
        char c = subjectWord[i];
        if(countMap.find(c) == countMap.end() || countMap.find(c)->second == 0){
            return 0;
        }
        (countMap.find(c)->second)--;
    }

    return 1;
}

int getCost(int start, int wordIndex){
    string word = words[wordIndex];
    int cost = 0;
    for(int i = 0 ; i < word.size(); i++){
        if(word[i] != subjectWord[start+i]){
            cost++;
        }
    }

    return cost;
}

int solve(int index){
    if(index == subjectWord.size()){
        return 0;
    }
    if(dp[index] != INT_MAX){
        return dp[index];
    }

    int minCost = INT_MAX;

    for(int i = 0 ; i < words.size(); i++){
        bool end = isIncluded(index, i);
        if(end == false){
            continue;
        }
        int cost = getCost(index, i);
        int nextCost = solve(index+words[i].size());
        if(nextCost == -1){
            continue;
        }

        if(minCost > cost+ nextCost){
            minCost = cost + nextCost;
        }
    }

    if(minCost == INT_MAX){
        return dp[index] = -1;
    }else {
        return dp[index] = minCost;
    }
}
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int N, totalCount;
map<char, int> alphabets;
string s;

bool isIncluded(int begin, int end){
    map<char,int> candidateAlphabets;
    for(int i = begin; i < end; i++){
        if(candidateAlphabets.find(s[i]) == candidateAlphabets.end()){
            candidateAlphabets.insert(make_pair(s[i],0));
        }
        (candidateAlphabets.find(s[i])->second)++;
    }
    map<char,int>::iterator iter;
    for(iter = candidateAlphabets.begin(); iter != candidateAlphabets.end(); iter++){
        if(alphabets.find(iter->first) == alphabets.end() || alphabets.find(iter->first)->second != iter->second){
            return false;
        }
    }
    
    for(iter = alphabets.begin(); iter != alphabets.end(); iter++){
        if(candidateAlphabets.find(iter->first) == candidateAlphabets.end() || candidateAlphabets.find(iter->first)->second != iter->second){
            return false;
        }
    }

    return true;
}

void addWords(int begin, int end, string s, bool isForward){
    int mid = (begin+ end)/2;
    int mid2 = (begin+end+1)/2;
    
    addWords(begin, mid, isForward? )
}

int main(){
    
    cin >> N;

    totalCount = 0;

    for(int i = 0; i < N; i++){
        char c;
        int count;
        cin >> c >> count;
        alphabets.insert(make_pair(c, count));
        totalCount += count;
    }
    
    cin >> s;

    for(int i = 0 ; i < s.size() - totalCount + 1; i++){
        if(isIncluded(i, i+totalCount)){
            addWords(i, i+totalCount);
        }
    }

    cout << words.size();
}
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#define MOD_NUM 1337377

using namespace std;

typedef struct Trie{
    bool isEnd;
    Trie* children[26];
    Trie():isEnd(false){
        for(int i = 0 ; i < 26; i++){
            children[i] = NULL;
        }
    }

    void insert(string& s){
        Trie* node = this;
        for(int i = 0 ; i <s.size(); i++){
            int index = s[i]-'a';
            if(node->children[index] == NULL){
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool contains(string& s){
        Trie* node = this;
        for(int i = 0 ; i <s.size(); i++){
            
            int index = s[i]-'a';

            if(node->children[index] == NULL){
                return false;
            }
            node = node->children[index];
        }
        return true;
    }

    bool exist(string& s){
        Trie* node = this;
        for(int i = 0 ; i <s.size(); i++){
            int index = s[i]-'a';
            if(node->children[index] == NULL){
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }
} Trie;

string longWord;
int size;
vector<int> memo;
Trie smallWordRoot;
int smallSize = 0;

int solve();

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> longWord;
    size = longWord.size();
    memo.assign(size+1,0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        smallWordRoot.insert(s);
        if(smallSize < s.size()){
            smallSize = s.size();
        }
    }

    cout << solve() << endl;
}

int solve(){

    vector<bool> visited(size+1, 0);
    q.push(0);
    visited[0] = true;
    memo[0] = 1;
    for(int baseIndex = 0; baseIndex < size; baseIndex++){
        if(!visited[baseIndex]){
            continue;
        }
        int index = baseIndex;
        string leftWord;
        
        string::iterator iter = longWord.begin() + index;
        while(iter != longWord.end() && leftWord.size() <= smallSize){
            leftWord+=(*iter);
            iter++;
            index++;
            if(smallWordRoot.exist(leftWord)){
                memo[index] = (memo[index] % MOD_NUM + memo[baseIndex] % MOD_NUM) % MOD_NUM;
                if(!visited[index]){
                    visited[index] = true;
                }
            }
        }
    }
    
    return memo[size];
}
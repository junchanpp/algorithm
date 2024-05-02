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
} Trie;

string longWord;
int size;
vector<int> memo;
Trie smallWordRoot;

int solve();

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> longWord;
    size = longWord.size();
    memo.assign(size,0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        smallWordRoot.insert(s);
    }

    cout << solve() << endl;
}

int solve(){

    for(int baseIndex = 0; baseIndex < size; baseIndex++){
        int index = baseIndex;
        Trie* t = &smallWordRoot;
        
        while(index < size && index - baseIndex <= 100){
            char c = longWord[index];
            t = t->children[c-'a'];
            if(t == NULL){
                break;
            }
            if(t->isEnd){
                memo[index] = (memo[index] + (baseIndex == 0 ? 1 :memo[baseIndex-1])) % MOD_NUM;
            }
            index++;
        }
    }
    
    return memo[size-1];
}
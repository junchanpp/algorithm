#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#define ALPHABETS 26

using namespace std;

typedef struct Trie{
    bool hasNext;
    unordered_map<char, Trie*> children;

    Trie(): hasNext(true){}

    void insert(string& s){
        Trie* node = this;
        for(int i = 0 ; i < s.size(); i++){
            char c = s[i];
            if(node->children.find(c) == node->children.end()){
                node->children.insert(make_pair(c, new Trie()));
            }
            node = node->children.find(c)->second;
        }
        node->hasNext = false;
    }

    bool contains(string& s){
        Trie* node = this;
        for(int i = 0 ; i < s.size(); i++){
            char c = s[i];
            if(node->children.size() == 0){
                return true;
            }
            if(node->children.find(c) == node->children.end()){
                return false;
            }
            node = node->children.find(c)->second;
        }
        return true;
    }
    bool isExist(string& s){
        Trie* node = this;
        for(int i = 0 ; i < s.size(); i++){
            char c = s[i];
            if(node->children.find(c) == node->children.end()){
                return false;
            }
            node = node->children.find(c)->second;
        }
        return !node->hasNext;
    }
} Trie;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<bool> answers;
    while(T--){
        Trie trie;
        int n;
        cin >> n;
        bool answer = true;
        for(int i = 0 ; i < n; i++){
            string s;
            cin >> s;
            if(i != 0 && trie.contains(s)){
                answer = false;
            }
            trie.insert(s);
        }
        answers.push_back(answer);
    }

    for(int i = 0 ; i < answers.size(); i++){
        cout << (answers[i] ? "YES" : "NO") << endl;
    }
}
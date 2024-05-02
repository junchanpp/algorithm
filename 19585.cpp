#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <utility>
using namespace std;

unordered_set<string> nameSet;

typedef struct Trie{
    bool canEnd;
    map<char, Trie*> children;

    Trie():canEnd(false){}
    ~Trie(){
        for(map<char, Trie*>::iterator iter = children.begin(); iter != children.end(); iter++){
            delete iter->second;
        }
    }

    void insert(string& s){
        Trie* node = this;
        for(int i = 0; i < s.size(); i++){
            if(node->children.find(s[i]) == node->children.end()){
                node->children.insert(make_pair(s[i], new Trie()));
            }
            node = node->children.find(s[i])->second;
        }
        node->canEnd = true;
    }

    bool isExist(string& s){
        Trie* node = this;

        for(int i = 0; i <s.size(); i++){
            if(node->children.find(s[i]) == node->children.end()){
                break;
            }
            node= node->children.find(s[i])->second;
            if(node->canEnd){
                if(nameSet.find(s.substr(i+1)) != nameSet.end()){
                    return true;
                }
            }
        }

        return false;
    }

}Trie;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    Trie* colorTrie = new Trie();
    Trie* nameTrie = new Trie();

    int  C, N;
    cin >> C >> N;

    for(int i = 0; i < C;i++){
        string s;
        cin >> s;
        colorTrie->insert(s);
    }
    for(int i = 0; i < N;i++){
        string s;
        cin >> s;
        nameSet.insert(s);
    }

    vector<bool> answers;
    
    int Q;
    cin >> Q;
    for(int i = 0; i < Q;i++){
        string s;
        cin >> s;
        answers.push_back(colorTrie->isExist(s));
    }

    for(int i = 0; i < answers.size();i++){
        cout << (answers[i] ? "Yes" : "No") << '\n';
    }
}
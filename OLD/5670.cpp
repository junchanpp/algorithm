#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int ctoi(char& c){
    return c-'a';
}

typedef struct Trie{
    bool isEnd;
    Trie* children[26];
    vector<int> charList;

    Trie():isEnd(false){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
            charList.resize(0);
        }
    }
    ~Trie(){
        for(int i = 0; i <26;i++){
            delete children[i];
        }
    }

    void insert(string& s){
        Trie* node = this;
        for(int i = 0 ; i < s.size(); i++){
            int index = ctoi(s[i]);
            if(node->children[index] == NULL){
                node->children[index] = new Trie();
                node->charList.push_back(index);
            }
            node = node->children[index];
        }
        node->isEnd = true;  
    }
    long long count(){
        if(charList.size() == 0){
            return 0;
        }
        if(charList.size() == 1){
            return children[charList[0]]->count() + (isEnd ? 1 : 0);
        }

        long long c = 0;
        for(int i = 0; i < charList.size();i++){
            c += 1 + children[charList[i]]->count();
        }

        return c;
    }
    long long count(string& s){
        Trie* node = this;
        long long c = this->charList.size() == 1 ? 1 : 0;
        for(int i = 0 ; i < s.size();i++){
            int index = ctoi(s[i]);
            c += (node->charList.size() == 1 && node->isEnd == false ? 0 : 1);
            node = node->children[index];
        }

        return c;
    }
} Trie;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<double> answers;

    string t;
    while(getline(cin, t)){
        if(cin.eof() || t.size() == 0){
            break;
        }
        int N = stoi(t);
        Trie* trie = new Trie();
        vector<string> stringList;
        for(int i = 0; i < N;i++){
            string s;
            getline(cin, s);
            trie->insert(s);
            stringList.push_back(s);
        }

        long long c = 0;
        for(int i = 0 ; i < stringList.size(); i++){
            c+= trie->count(stringList[i]);
        }
        answers.push_back((double)c/stringList.size());
        
        delete trie;
    }

    for(int i = 0 ; i < answers.size(); i++){
        cout << fixed << setprecision(2) << round(100* answers[i])/100 << '\n';
    }

}
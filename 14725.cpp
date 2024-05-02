#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

typedef struct Trie{
    int depth;
    map<string, Trie*> children;
    Trie(int depth):depth(depth){}
    ~Trie(){
        
        for(map<string, Trie*>::iterator iter = children.begin(); iter != children.end(); iter++){
            delete iter->second;
        }
    }

    void insert(vector<string>& v){
        Trie* node = this;
        for(int i = 0 ; i < v.size(); i++){
            if(node->children.find(v[i]) == node->children.end()){
                node->children.insert(make_pair(v[i], new Trie(i+1)));
            }
            
            node = node->children.find(v[i])->second;
        }
        
    }
    void print(){
        Trie*node = this;
        for(map<string, Trie*>::iterator iter = children.begin(); iter != children.end(); iter++){
            for(int i = 0 ; i < depth;i++){
                cout << "--";
            }
            cout << iter->first << '\n';
            iter->second->print();
        }
    }
} Trie;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    Trie root(0);

    for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        vector<string> stringList(K);
        for(int j = 0; j < K; j++){
            cin >> stringList[j];
        }
        root.insert(stringList);
    }

    root.print();
}
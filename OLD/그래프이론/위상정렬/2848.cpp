#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

bool edge[26][26]={0,};
int inDegree[26]={0,};
bool isExist[26]={0,};
vector<string> stringVector;

int N;

int getEqualSize(int a, int b){
    int size = max(stringVector[a].length(),stringVector[b].length());
    int equalSize = 0;
    while(equalSize < size && stringVector[a][equalSize] == stringVector[b][equalSize]){equalSize++;}
    return equalSize;
}

int main(){
    cin >> N;
    
    for(int i = 0 ; i < N;i++){
        string s;
        cin >> s;
        stringVector.push_back(s);
        for(int i = 0 ; i < s.length(); i++){
            isExist[s[i]-'a']=1;
        }
    }

    for(int i = 0 ; i < N; i++){
        for(int j = i+1 ; j < N; j++){
            int equalSize = getEqualSize(i,j);
            if(equalSize >= stringVector[i].length() || equalSize >= stringVector[j].length()){
                if(stringVector[i] > stringVector[j]){
                    cout << "!";
                    return 0;
                }else {
                    continue;
                }
            }
            if(edge[stringVector[i][equalSize]-'a'][stringVector[j][equalSize]-'a']==0){
                edge[stringVector[i][equalSize]-'a'][stringVector[j][equalSize]-'a'] = 1;
                inDegree[stringVector[j][equalSize]-'a']++;
            }
        }
    }

    queue<int> q;
    for(int i = 0 ; i < 27; i++){
        if(isExist[i] && inDegree[i]==0)q.push(i);
    }
    if(q.size()>1){
        cout << "?" << endl;
        return 0;
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int i = 0; i < 26; i++){
            if(edge[node][i]){
                inDegree[i]--;
                if(inDegree[i]==0)q.push(i);
            }
        }
        if(q.size()>1){
            cout << "?" << endl;
            return 0;
        }
    }
    bool isAnsExist[27]= {0,};

    for(int i = 0; i < ans.size(); i++){
        isAnsExist[ans[i]]=1;        
    }
    for(int i = 0 ; i < 26; i++){
        if(isAnsExist[i] != isExist[i]){
            cout << "!" << endl;
            return 0;
        }
    }
    for(int i = 0 ; i < ans.size(); i++){
        cout << (char)(ans[i]+'a');
    }

    return 0;
}
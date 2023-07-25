#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
bool board[5][5];

bool isSGreaterThanY(vector<int> index){
    int sCount = 0;
    int yCount = 0;
    for(int i = 0; i < 7;i++){
        int y = index[i]/5;
        int x= index[i]%5;
        if(board[y][x] == 1)sCount++;
        else yCount++;
    }
    return sCount >=4;
}
bool isAllLink(vector<int> index){
    set<int> v(index.begin(),index.end());
    queue<int> checkQ;
    checkQ.push(*(v.begin()));
    v.erase(v.begin());
    while(!checkQ.empty()){
        int nowIndex = checkQ.front();
        checkQ.pop();
        set<int>::iterator iter;
        if((iter = v.find(nowIndex+5)) !=v.end()){
            checkQ.push(*iter);
            v.erase(iter);
        }
        if((iter = v.find(nowIndex-5)) !=v.end()){
            checkQ.push(*iter);
            v.erase(iter);
        }
        if(nowIndex%5 != 4 &&( iter = v.find(nowIndex+1)) !=v.end()){
            checkQ.push(*iter);
            v.erase(iter);
        }
        if(nowIndex%5 != 0 &&( iter = v.find(nowIndex-1)) !=v.end()){
            checkQ.push(*iter);
            v.erase(iter);
        }   
    }
    return v.empty();
}

int main(){
    for(int i = 0 ; i < 5; i++){
        string s;
        cin >> s;
        for(int j = 0 ; j< 5; j++){
            board[i][j] = s[j]== 'S';
        }
    }

    vector<bool> chooseList(25,true);

    for(int i = 0; i <18;i++){
        chooseList[i] = false;
    }

    int count = 0;
    do{
        vector<int> indexSelected;
        for(int i = 0; i < 25;i++)if(chooseList[i]==true)indexSelected.push_back(i);
        if(isSGreaterThanY(indexSelected) && isAllLink(indexSelected))count++;
    }while(next_permutation(chooseList.begin(),chooseList.end()));

    cout << count;
}
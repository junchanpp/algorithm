#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N,K;

bool isExist(const set<int>& plugs, const int& plug){
    return plugs.find(plug) != plugs.end();
}
void changePlug(set<int>& plugs,vector<int>& plugOrder, const int index){
    set<int>::iterator deleteTarget= plugs.begin();
    int deleteTargetForNextIndex = -1;
    for(set<int>::iterator iter = plugs.begin(); iter != plugs.end();iter++){
        bool isFind = false;
        for(int i = index+1 ; i < plugOrder.size(); i++){
            if(plugOrder[i] == *iter){
                if(deleteTargetForNextIndex < i){
                    deleteTargetForNextIndex = i;
                    deleteTarget = iter;
                }
                isFind  = true;
                break;
            }
        }
        if(!isFind){
            deleteTarget = iter;
            break;
        }
    }

    plugs.erase(deleteTarget);
    plugs.insert(plugOrder[index]);
}

int main(){
    cin >> N >> K;
    vector<int> plugOrder(K);
    for(int i = 0 ; i < K; i++){
        cin >>plugOrder[i];
    }
    int count = 0;
    set<int> plugs;
    for(int i = 0; i < K ; i++){
        if(plugs.size() < N)plugs.insert(plugOrder[i]);
        else {
            if(isExist(plugs, plugOrder[i]))continue;
            changePlug(plugs, plugOrder , i);
            count++;
        }
    }
    cout << count;
    return 0;
}
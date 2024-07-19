#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

int n;
deque<int> deq;
pair<bool,pair<int,int> > nodeCalc[101010];

int getNumber(bool isMax){
    int value;
    if(!isMax){
        value = deq.back();
        deq.pop_back();
    }else {
        value = deq.front();
        deq.pop_front();
    }
    return value;
}

int solve(int nodeCalcIndex, bool isNeedMax){
    bool isPlus = nodeCalc[nodeCalcIndex].first;
    int node1 = nodeCalc[nodeCalcIndex].second.first;
    int node2 = nodeCalc[nodeCalcIndex].second.second;

    bool isNode1GetMax = isNeedMax;
    bool isNode2GetMax = isNeedMax ? isPlus : !isPlus;
    int num1,num2;
    if(node1 >n){
        num1 = solve(node1-n-1,isNode1GetMax);
    } else {
        num1 = getNumber(isNode1GetMax);
    }
    if(node2 >n){
        num2 = solve(node2-n-1,isNode2GetMax);
    } else {
        num2 = getNumber(isNode2GetMax);
    }
    return num1 + (isPlus ? num2 : -1*num2);
}

int main(){
    cin >> n;
    for(int i = 0; i< n;i++){
        int temp;
        cin >> temp;
        deq.push_back(temp);
    }
    for(int i = 0; i<n-1;i++){
        int node1,node2;
        char cal;
        cin >> cal >> node1 >> node2;
        nodeCalc[i] = make_pair(cal == '+',make_pair(node1,node2));
    }

    sort(deq.begin(),deq.end(),greater<int>());

    int answer = solve(n-2,true);

    cout << answer;
    return 0;
}
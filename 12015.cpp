#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& memo, int num);

int main(){
    int n;
    vector<int> v;
    cin >> n;
    vector<int> memo;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    memo.push_back(v[0]);
    for(int i = 1 ; i < n ; i++){
        int targetNum = v[i];
        if(memo.back() < targetNum){
            memo.push_back(targetNum);
            continue;
        }
        int lo = 0;
        int hi = memo.size()-1;
        while(lo< hi){
            int middle = (lo+hi)/2;
            if(targetNum <= memo[middle]){
                hi = middle;
            }else {
                lo = middle+1;
            }
        };
        memo[lo] = targetNum;
    }
    cout << memo.size();
}
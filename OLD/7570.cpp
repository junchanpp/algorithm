#include <iostream>
#include <vector>

using namespace std;

int getMinCountChange(int);

vector<int> v;
vector<int> memo;

int n;

int main (){

    cin >> n;

    for(int i = 0; i< n; i++){
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp);
        memo.push_back(0);
    }

    int ans =1;
    for(int i = 0; i< n; i++){
    ans = max(ans,getMinCountChange(i));
    }

    printf("%d", n-ans);
}

int getMinCountChange(int targetIndex){
    
    if(targetIndex == n-1){
        return 1;
    }
    if(memo[targetIndex]!=0){
        return memo[targetIndex];
    }

    int count = 1;
    for(int i = targetIndex+1 ; i < n; i++){
        if(v[targetIndex] == v[i]-1){
            count = count + getMinCountChange(i);
        }
    }

    memo[targetIndex] = count;
    return count;
}
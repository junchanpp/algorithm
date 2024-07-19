#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef struct Node
{
    int first;
    int second;
} Node;


int main(){
    int n;
    int* v= new int[500010]();
    int* dp= new int[500010]();
    vector<Node> lis;
    scanf("%d", &n);

    for(int i = 0 ; i < n; i++){
        int temp1, temp2;
        scanf("%d", &temp1);
        scanf("%d", &v[temp1]);
    }
    for(int i = 0; i <= 500000; i++){
        if(v[i]==0)continue;

        Node node = {i,v[i]};
        if(lis.size()==0){
            lis.push_back(node);
            dp[i] = lis.size();
            continue;
        }

        if(lis.back().second < v[i]){
            lis.push_back(node);
            dp[i] = lis.size();
            continue;
        }

        int lo = 0, hi = lis.size();
        while(lo< hi){
            int middle = (lo+hi)/2;

            if(v[i] > lis[middle].second){
                lo = middle+1;
            } else {
                hi = middle;
            }
        }
        lis[lo] = node;
        dp[i] = lo+1;
    }

    printf("%d\n", n-lis.size());

    int index = lis.size();
    stack<int> s;
    for(int i = 500000; i >= 0; i--){
        if(dp[i] == 0)continue;

        if(index == dp[i]){
            index--;
        } else {
            s.push(i);
        }
    }
    while(s.size() > 0){
        printf("%d\n", s.top());
        s.pop();
    }    
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n ;
    scanf("%d", &n);

    int* a = new int[n];

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }

    vector<int> ans;
    int* memo = new int[n]; // 각각이 몇번째인지

    ans.push_back(a[0]);
    memo[0] = 1;
    for(int i = 1; i< n ; i++){
        if(ans.back() < a[i]){
            ans.push_back(a[i]);
            memo[i] = ans.size();
            continue;
        }

        int lo = 0;
        int hi = ans.size()-1;
        while(lo<hi){
            int middle = (lo+hi)/2;

            if(a[i] > ans[middle]){
                lo = middle+1;
            }else {
                hi = middle;
            }
        }
        ans[lo] = a[i];
        memo[i] = lo+1; // a의 i번째 요소는 lo번째에 위치
    }

    int count = ans.size();

    printf("%d\n", count);

    stack<int> st;
    for(int i = n -1; i >= 0; i--){
        if(memo[i] == count){
            st.push(a[i]);
            count--;
        }
    }

    while(!st.empty()){
        printf("%d\n", st.top());
        st.pop();
    }
}
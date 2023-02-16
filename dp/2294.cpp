//2023-02-16 20:43:38 start
//2023-02-16 20:58:14 end
#include <iostream>
#include <string.h>

using namespace std;

int memo[10001];

int main(){
    int n,k; // n <=100, k <= 10000
    cin >> n >> k;

    memset(memo, -1, sizeof(memo));

    for(int i =0; i< n; i++){
        int temp;
        cin >> temp;
        if(temp <= k)memo[temp] = 1;
    }

    for(int i = 1; i<= k; i++) {
        for(int j = 1; j <= i/2; j++){
            if(memo[j] != -1 && memo[i-j] != -1){
                int result = memo[j]+memo[i-j];
                if(memo[i] == -1 || memo[i] > result) memo[i] = result;
            }
        }
    }

    cout << memo[k];
}
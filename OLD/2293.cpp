#include <iostream>

using namespace std;

int n, k;
int arr[10010] = {0,};
int coin[101];

int calculateCoin(void);

int main(){
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++ ){
        scanf("%d", &coin[i]);
    }
    printf("%d", calculateCoin());
}

int calculateCoin(){
    arr[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k ; j++){
            if(i==0){
                if(j % coin[i] ==0){
                    arr[j] = 1;
                } else {
                    arr[j] = 0;
                }
            } else {
                if(coin[i]<=j)
                    arr[j] = arr[j]+arr[j-coin[i]];
            }
        }
    }

    return arr[k];
}
#include <iostream>
#include <vector>

using namespace std;

int n;

int main (){

    cin >> n;

    int arr[n+10];

    for(int i = 0; i< n; i++){
        int tmp;
        scanf("%d", &tmp);
        arr[tmp] = i;
    }

    int ans =1;
    int tmpMax = 1;
    for(int i = 0; i< n-1; i++){
        if(arr[i] < arr[i+1]){
            ans = max(ans, ++tmpMax);
        }else {
            tmpMax = 1;
        }
    }

    printf("%d", n-ans);
}
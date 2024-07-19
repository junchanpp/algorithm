//2023-02-17 19:10:00 start
//2023-02-17 19:19:00 end
//2023-02-17 19:20:00 start
//2023-02-17 19:26:00 end

#include <iostream>
#include <algorithm>

using namespace std;

/*

n명의 원생, k개의 조
a,b,c d,e f

*/

int main(){
    int n,k;

    cin >> n >> k;

    int arr[n];
    int newArr[n-1];

    for(int i = 0; i< n;i++){
        cin >> arr[i];
        if(i > 0)newArr[i-1] = arr[i] - arr[i-1];
    }

    sort(newArr, newArr + sizeof(newArr)/sizeof(int));

    int sum = 0;
    for(int i = 0 ; i < n-1-(k-1); i++){
        sum += newArr[i];
    }

    cout << sum << endl;
}
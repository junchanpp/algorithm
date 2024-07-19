#include <iostream>

using namespace std;

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0 ; i < n; i++){
            if(k == i)continue;
            for(int j = 0 ; j < n; j++){
                if(k == j && i == j)continue;

                arr[i][j] = min(arr[i][k]+arr[k][j],arr[i][j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
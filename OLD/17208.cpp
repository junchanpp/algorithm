#include <iostream>
#include <utility>
#include <math.h>

using namespace std;

int N,M,K;
pair<int, int> input[101];
int arr[101][301][301]= {0,};

int main(){
    cin >> N >> M >> K;

    for(int i = 1 ; i <= N; i++){
        cin >> input[i].first >> input[i].second;
    }
    

    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= M; j++){
            for(int u = 1; u <= K; u++){
                if(input[i].first <= j && input[i].second <= u){
                    arr[i][j][u] = max(arr[i-1][j - input[i].first][u-input[i].second]+1, arr[i-1][j][u]);
                } else {
                    arr[i][j][u] = arr[i-1][j][u];
                }
            }
        }
    }

    cout << arr[N][M][K];
}
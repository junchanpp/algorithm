#include <iostream>

using namespace std;

int N,K;
int arr[3][1000];
int memo[1000][1001][0x7+1];

bool isCanAddTile(int bitmask){
    return bitmask & 2;
}
int addTile(int row, int bitmask){
    int sum = 0;
    for(int i = 0 ; i < 3; i++){
        if(bitmask &( 1 << i))sum+=arr[i][row];
    }
    return sum;
}

int solve(int row, int k, int bitmask){
    if(row==N && (k==0 || !isCanAddTile(bitmask))){
        return sum;
    }
}

int main(){
    cin >> N >> K;
    for(int i =  0 ; i < 3; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int result = solve(0,K,0);
}
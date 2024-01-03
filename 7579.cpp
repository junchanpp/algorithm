#include <iostream>
#include <utility>
#include <math.h>

using namespace std;

int N, M;
int memo[101][10001];
int p1[101];
int p2[101];

int main(){
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> p1[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> p2[i];
    }

    for(int i = 1; i<= N; i++){
        for (int j = 0 ; j <= 10000; j++){
            if(j >= p2[i]){memo[i][j] = max(memo[i-1][j-p2[i]]+p1[i],memo[i-1][j]);}
            else {memo[i][j] = memo[i-1][j];}
        }
    }

    int cost = 0;
    while(memo[N][cost] < M)cost++;
    cout << cost;
}
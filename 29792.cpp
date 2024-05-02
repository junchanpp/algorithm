#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, K;//N,M 최대 49, K 최대 13
vector<long long> D;
vector<vector<long long> > boss;

long long memo[50][15*60+1];//처음 50은 캐릭터, 나중 901은 초단위

vector<long long> result;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;
    
    for(int i =0 ; i < N; i++){
        long long temp;
        cin >> temp;
        D.push_back(temp);
    }

    for(int i = 0 ; i < 50; i++){
        for(int j = 0 ; j <=900;j++){
            memo[i][j] =0;
        }
    }


    for(int i =0 ; i < K; i++){
        long long temp1,temp2;
        cin >> temp1 >> temp2;
        vector<long long> v;
        v.push_back(temp1);
        v.push_back(temp2);

        boss.push_back(v);
    }

    for(int i = 0 ; i < N; i++){
        long long damage = D[i];
        
        for(int j = 0; j < K; j++){
            long long spendTime = boss[j][0]/damage + (boss[j][0]%damage > 0 ? 1: 0);
            for(int k = 15*60 ; k >= spendTime;k--){
                memo[i][k] = max(memo[i][k], memo[i][k-spendTime] + boss[j][1]);
            }
        }
        result.push_back(memo[i][15*60]);
    }

    sort(result.begin(), result.end());

    long long sum = 0;
    while(M--){
        sum+= result.back();
        result.pop_back();
    }

    cout << sum;
}
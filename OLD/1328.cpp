#include <iostream>
#include <vector>
#define MOD_NUM 1000000007

using namespace std;

int N, L, R;
vector<vector<long long> > memo;
vector<vector<long long> > combi;

vector<long long> factorial;

void initFactorial();
void initCombi();
long long permu(int N, int p);
long long solve(int N, int seeCount);


int main(){
    
    cin >> N >> L >> R;

    initFactorial();
    initCombi();

    memo.assign(N+1,vector<long long>(N+1,-1));

    long long result = 0;
    for(int i = 1 ; i <= N; i++){//i번째에 현재 가장 높은 건물 배치
        result = result +  (((((solve(i-1,L-1)% MOD_NUM) * (solve(N-i,R-1) % MOD_NUM)) % MOD_NUM) * combi[N-1][i-1]) % MOD_NUM);
        result %= MOD_NUM;
    }
    
    cout << result << endl;
}

void initFactorial(){
    factorial.assign(N+1,0);
    factorial[0] = 1;
    for(long long i = 1; i <= N;i++){
        factorial[i] = (factorial[i-1] * i) % MOD_NUM;
    }
}
void initCombi(){
    combi.assign(N+1,vector<long long>(N+1,0));
    combi[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        combi[i][0] = combi[i][i] = 1;
        for (int j = 1; j <= i-1; j++) {
            combi[i][j] = (combi[i - 1][j] + combi[i - 1][j - 1]) % MOD_NUM;
        }
    }
}

long long permu(int N, int p){
    return (combi[N][p] * factorial[p]) % MOD_NUM;
}

long long solve(int N, int seeCount){
    if(N == 0 && seeCount == 0){
        return 1;
    }
    if(N >= 0 && seeCount == 0){
        return 0;
    }
    if(N == 0 && seeCount >= 0){
        return 0;
    }
    if(memo[N][seeCount] != -1){
        return memo[N][seeCount];
    }

    long long result = 0; 
    for(int i = 1; i <= N; i++){
        
        result = result + (solve(i-1, seeCount-1) * permu(N-1, N-i)) % MOD_NUM;
        result %= MOD_NUM;
    }

    return memo[N][seeCount] = result;
}
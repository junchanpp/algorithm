#include <iostream>

using namespace std;

struct Matrix{
    long long a_11;
    long long a_12;
    long long a_21;
    long long a_22;

};
struct Matrix2to1{
    long long a_11;
    long long a_21;
};

Matrix matrix={4,-1,1,0};
Matrix defaultMatrix={1,0,0,1};
Matrix2to1 matrix2to1={3,1};
Matrix memo[10000000];
bool isMemo[10000000]={0,};
long long MOD = 1000000007;

Matrix mul(const Matrix& m1, const Matrix& m2){
    long long a_11 = (m1.a_11*m2.a_11 + m1.a_12*m2.a_21 +MOD) % MOD;
    long long a_12 = (m1.a_11*m2.a_12 + m1.a_12*m2.a_22 + MOD) % MOD;
    long long a_21 = (m1.a_21*m2.a_11 + m1.a_22*m2.a_21 + MOD) % MOD;
    long long a_22 = (m1.a_21*m2.a_12 + m1.a_22*m2.a_22 + MOD) % MOD;

    Matrix newMatrix={a_11,a_12,a_21,a_22};
    return newMatrix;
}


Matrix2to1 mul(const Matrix& m1, const Matrix2to1& m2){
    long long a_11 = (m1.a_11*m2.a_11 + m1.a_12*m2.a_21 + MOD) % MOD;
    long long a_21 = (m1.a_21*m2.a_11 + m1.a_22*m2.a_21 + MOD) % MOD;
    
    Matrix2to1 newMatrix={a_11,a_21};
    return newMatrix;
}

Matrix solve2(long long n){
    Matrix answer = {1,0,0,1};
    while(n){
        if(n%2==1){
            answer = mul(answer,matrix);
        }
        matrix = mul(matrix,matrix);
        n/=2;
    }
    return answer;
}


int main(){
    long long n;
    cin >> n;

    if(n%2 == 1){
        cout << 0 << endl;
        return 0;
    }

    Matrix2to1 answer = mul(solve2((n)/2-1),matrix2to1);

    cout << answer.a_11 ;

    return 0;
}
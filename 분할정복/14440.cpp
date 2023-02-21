#include <iostream>

using namespace std;

struct Matrix{
    int a_11;
    int a_12;
    int a_21;
    int a_22;
};
struct Matrix2_1{
    int a_11;
    int a_21;
};
Matrix make_matrix(int a_11,int a_12, int a_21, int a_22){
    Matrix newMatrix={a_11,a_12,a_21,a_22};
    return newMatrix;
}

Matrix2_1 make_matrix2_1(int a_11, int a_21){
    Matrix2_1 newMatrix={a_11,a_21};
    return newMatrix;
}

Matrix matrix;
Matrix matrix0;
int x,y;
int a0,a1;
Matrix memo[10000001];
bool isMemo[10000001]={0,};
Matrix2_1 defaultMatrix;

Matrix multiple(const Matrix& matrix1,const Matrix& matrix2){
    int a_11 = matrix1.a_11*matrix2.a_11+matrix1.a_12*matrix2.a_21;
    int a_12 = matrix1.a_11*matrix2.a_12+matrix1.a_12*matrix2.a_22;
    int a_21 = matrix1.a_21*matrix2.a_11+matrix1.a_22*matrix2.a_21;
    int a_22 = matrix1.a_21*matrix2.a_12+matrix1.a_22*matrix2.a_22;
    Matrix newMatrix={a_11%100,a_12%100,a_21%100,a_22%100};
    return newMatrix;
}
Matrix2_1 multiple(const Matrix& matrix1,const Matrix2_1 matrix2){
    int a_11 = matrix1.a_11*matrix2.a_11+matrix1.a_12*matrix2.a_21;
    int a_21 = matrix1.a_21*matrix2.a_11+matrix1.a_22*matrix2.a_21;
    Matrix2_1 newMatrix={a_11%100,a_21%100};
    return newMatrix;
    
}
Matrix solve(int n){
    if(n < 10000001 && isMemo[n]){
        return memo[n];
    }
    if(n==1){
        return matrix;
    }
    if(n==0){
        return matrix0;
    }
    if(n%2 ==0){
        if(n >= 10000001){
            return multiple(solve(n/2),solve(n/2));
        }
        memo[n] = multiple(solve(n/2),solve(n/2));
        isMemo[n]= true;
    }else{
        if(n >=10000001){
            return multiple(multiple(solve((n-1)/2),solve((n-1)/2)),matrix);
        }
        memo[n] = multiple(multiple(solve((n-1)/2),solve((n-1)/2)),matrix);
        isMemo[n]= true;
    }

    return memo[n];
}

int main(){
    int n;
    cin >> x>> y >> a0 >> a1 >> n;
    matrix = make_matrix(x,y,1,0);
    matrix0 = make_matrix(1,0,0,1);
    defaultMatrix = make_matrix2_1(a1,a0);
    if(n == 0){
        cout << (a0 < 10 ? "0" : "") << a0;
        return 0;
    }

    Matrix2_1 answer = multiple(solve(n-1),defaultMatrix);

    cout << (answer.a_11 < 10 ? "0" : "") <<answer.a_11 ;
}
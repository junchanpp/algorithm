#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<vector<long long> > earned;
vector<vector<long long> > rowSum;//행
vector<vector<long long> > columnSum;//열

int main(){
    cin >> N;
    earned.assign(N, vector<long long>(N, 0));
    rowSum.assign(N, vector<long long>(N, 0));
    columnSum.assign(N, vector<long long>(N, 0));
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> earned[i][j];
        }
    }
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(j == 0){
                rowSum[i][0] = earned[i][0];
                columnSum[0][i] = earned[0][i];
                continue;
            }
            rowSum[i][j] = rowSum[i][j-1] + earned[i][j];
            columnSum[j][i] = columnSum[j-1][i] + earned[j][i];
        }
    }

    long long maxSum = INT_MIN;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){//시작점 선정
            long long currentSum = 0;
            for(int size = 0; size <= min(N-i-1, N-j-1); size++){
                currentSum += rowSum[i+size][j+size] - (j == 0 ? 0 : rowSum[i+size][j-1]) + columnSum[i+size][j+size] -  (i == 0 ? 0 : columnSum[i-1][j+size]) - earned[i+size][j+size];
                if(currentSum > maxSum){
                    maxSum = currentSum;
                }

            }
        }
    }

    cout << maxSum;




}
#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> A;
vector<vector<vector<vector<int> > > > memo;
vector<int> v1, v2;
int C,D,d;
int I, J;

int solve(int i,int j, bool isVacationI, bool isVacationJ){
    if(i == I && j == J){
        return 0;
    }
    if(i == I){
        return (J-j)*C + (J-j)*d + (isVacationI ? 0 : D);
    }
    if(j == J){
        return (I-i)*C + (I-i)*d + (isVacationJ ? 0 : D);
    }
    if(memo[i][j][isVacationI][isVacationJ]){
        return memo[i][j][isVacationI][isVacationJ];
    }

    int minNum = solve(i+1,j+1,0,0) + (v1[i] == v2[j] ? C : 2 * C);
    minNum = min(minNum, solve(i+1,j,0,1) + C + d + (isVacationJ ? 0 : D));
    minNum = min(minNum, solve(i,j+1,1, 0) + C + d + (isVacationI ? 0 : D));

    return memo[i][j][isVacationI][isVacationJ] = minNum;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> C >> D >> d;
        v1.clear();
        while(1){
            int temp;
            cin >> temp;
            if(temp == 0){
                break;
            }
            v1.push_back(temp);
        }
        v2.clear();
        while(1){
            int temp;
            cin >> temp;
            if(temp == 0){
                break;
            }
            v2.push_back(temp);
        }


        memo.assign(v1.size(), vector<vector<vector<int> > >(v2.size(),vector<vector<int> >(2, vector<int>(2,0))));
        I = v1.size();
        J = v2.size();

        cout << solve(0,0,false,false) << endl;
        
    }
}
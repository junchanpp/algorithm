#include <iostream>
#include <math.h>

using namespace std;
int n;
int score[100001][3];
int dp_max[3];
int dp_min[3];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> score[i][0] >> score[i][1] >> score[i][2];
    }
    dp_max[0] = score[n-1][0];
    dp_max[1] = score[n-1][1];
    dp_max[2] = score[n-1][2];
    dp_min[0] = score[n-1][0];
    dp_min[1] = score[n-1][1];
    dp_min[2] = score[n-1][2];
    for(int i = n-2; i>=0;i--){
        int temp[3];
        temp[0] = score[i][0]+ max(dp_max[0],dp_max[1]);
        temp[1] = score[i][1]+ max(max(dp_max[0],dp_max[1]),dp_max[2]);
        temp[2] = score[i][2]+ max(dp_max[1],dp_max[2]);
        dp_max[0] = temp[0];
        dp_max[1] = temp[1];
        dp_max[2] = temp[2];
        temp[0] = score[i][0]+ min(dp_min[0],dp_min[1]);
        temp[1] = score[i][1]+ min(min(dp_min[0],dp_min[1]),dp_min[2]);
        temp[2] = score[i][2]+ min(dp_min[1],dp_min[2]);
        dp_min[0] = temp[0];
        dp_min[1] = temp[1];
        dp_min[2] = temp[2];
    }
    cout << max(max(dp_max[0],dp_max[1]),dp_max[2]) << " ";
    cout << min(min(dp_min[0],dp_min[1]),dp_min[2]) << endl;
}
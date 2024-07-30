#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N;
vector<int> inputs;
vector<int> sum;

int best;

void solve(int index, int diff, int gotValue){
    if(diff == 0 && gotValue > best){
        best = gotValue;
    }
    if(index >= 0){
        if(sum[index] + gotValue <= best){
            return;
        }
        if(abs(diff) > sum[index]){
            return;
        }

        solve(index-1, diff + inputs[index], gotValue + inputs[index]);//내가 가져갈 때
        solve(index-1, diff - inputs[index], gotValue + inputs[index]);//상대방이 가져갈 때
        solve(index-1, diff, gotValue);//그냥 팔 때
    }
}


int main(){
    while(1){
        cin >> N;
        if(N == 0){
            break;
        }
        best = 0;
        sum.clear();
        inputs.clear();

        sum.assign(N,0);
        inputs.assign(N,0); 

        for(int i = 0; i < N; i++){cin >> inputs[i];sum[i]=(i == 0 ?  0 : sum[i-1])  + inputs[i];}

        solve(N-1, 0, 0);
        cout << sum[N-1] - best << '\n';
    }
    

}
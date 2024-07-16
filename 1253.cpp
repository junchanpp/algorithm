#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inputs;
int N;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    inputs.assign(N,0);

    for(int i=0;i<N;i++){
        cin >> inputs[i];
    }
    sort(inputs.begin(), inputs.end());

    unordered_set<int> sets;
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        int s = 0;
        int e = N-1;
        while(s < e){
            if(s == i){
                s++;
            }
            else if(e == i){
                e--;
            }
            else if(inputs[s]+inputs[e] == inputs[i]){
                cnt++;
                break;
            } else if(inputs[s]+inputs[e] < inputs[i]){
                s++;
            } else {
                e--;
            }

        }
    }

    cout << cnt;
}
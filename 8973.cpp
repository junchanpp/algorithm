#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v1;
vector<int> v2;
vector<vector<int> > v;



int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    v1.assign(N);
    v2.assign(N);
    v.assign(N,vector<int>(N));

    for(int i = 0 ; i < N; i++){
        cin >> v1[i];
    }
    for(int i = 0 ; i < N; i++){
        cin >> v2[i];
    }


    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            v[i][j] = v1[i] * v2[j];
        }
    }



}
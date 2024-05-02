#include <iostream>
#include <vector>
#include <cmath>
#include <string>


using namespace std;

int N, K;
vector<int> v;
int main(){
    cin >> N;

    v.assign(N);

    for(int i = 0 ;i < N; i++){
        cin >> v[i];
    }

    cin >> K;
}
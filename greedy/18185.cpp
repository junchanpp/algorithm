#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> ra(N);
    int cost = 0;

    for(int i = 0 ; i < N ; i++){
        cin >>ra[i];
    }
    for(int i = 0 ; i < N-2; i++){
        if(ra[i+1] > ra[i+2]){
            int minCostTemp =  min(ra[i],ra[i+1]-ra[i+2]);
            ra[i]-=minCostTemp;
            ra[i+1]-=minCostTemp;
            cost+=minCostTemp*5;
        }
        int minCost= min(ra[i],min(ra[i+1],ra[i+2]));
        cost+= minCost*7;
        ra[i]-=minCost;
        ra[i+1]-=minCost;
        ra[i+2]-=minCost;
    }
    for(int i = 0 ; i < N-1; i++){
        int minCost= min(ra[i],ra[i+1]);
        cost+= minCost*5;
        ra[i]-=minCost;
        ra[i+1]-=minCost;
    }
    for(int i = 0 ; i < N; i++){
        int minCost= ra[i]*3;
        cost+= minCost;
        ra[i]-=minCost;

    }

    cout << cost;

}
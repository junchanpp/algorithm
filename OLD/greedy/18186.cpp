#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    long long N, B, C;
    cin >> N >> B >> C;
    vector<long long> ra(N);
    long long cost = 0;

    for(int i = 0 ; i < N ; i++){
        cin >>ra[i];
    }
    if(B >C){
        for(int i = 0 ; i < N-2; i++){
            if(ra[i+1] > ra[i+2]){
                long long minCostTemp =  min(ra[i],ra[i+1]-ra[i+2]);
                ra[i]-=minCostTemp;
                ra[i+1]-=minCostTemp;
                cost+=minCostTemp*(B+C);
            }
            long long minCost= min(ra[i],min(ra[i+1],ra[i+2]));
            cost+= minCost*(B+2*C);
            ra[i]-=minCost;
            ra[i+1]-=minCost;
            ra[i+2]-=minCost;
        }
        for(int i = 0 ; i < N-1; i++){
            long long minCost= min(ra[i],ra[i+1]);
            cost+= minCost*(B+C);
            ra[i]-=minCost;
            ra[i+1]-=minCost;
        }
    }
    
    
    for(int i = 0 ; i < N; i++){
        long long minCost= ra[i]*B;
        cost+= minCost;
        ra[i]-=minCost;

    }

    cout << cost;

}
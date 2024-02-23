#include <iostream>

using namespace std;

long long getChickenForRegular(int P, int M, int F, int C){
    long long extraChicken = 0;
    long long nowCoupon = (M/P)*C;

    while(nowCoupon >= F){
        long long nowExtraChicken = nowCoupon / F;
        extraChicken += nowExtraChicken;
        nowCoupon = nowCoupon - nowExtraChicken * F + nowExtraChicken * C;
    }
    
    return extraChicken;
}

long long getChickenForNotRegular(int P, int M, int F, int C){
    return ((M/P)*C)/F;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int P, M, F, C;
        
        scanf("%d %d %d %d", &P, &M, &F, &C);
        printf("%lld\n", getChickenForRegular(P,M,F,C) - getChickenForNotRegular(P,M,F,C));
    }

    return 0;

}
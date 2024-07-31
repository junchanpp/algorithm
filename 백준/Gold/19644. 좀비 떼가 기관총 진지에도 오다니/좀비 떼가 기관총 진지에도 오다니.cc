#include <iostream>
#include <vector>

using namespace std;

int L, Ml, Mk, Cammo;
vector<int> inputs;
vector<int> attackStops;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> L;
    cin >> Ml >> Mk;
    cin >> Cammo;
    inputs.assign(L, 0);
    attackStops.assign(L, 0);
    for(int i = 0 ; i < L; i++){
        cin >> inputs[i];
    }

    
    int nowIndex = -1;
    int attackCount = 0;
    while(nowIndex < L){
        if(nowIndex + 1 < L && inputs[nowIndex+1] > (attackCount + 1 + attackStops[nowIndex])*Mk){
            if(Cammo == 0){
                cout << "NO";
                return 0;
            }
            Cammo--;
            if(nowIndex >= 0){
                attackCount += attackStops[nowIndex];
            }
            
            nowIndex++;
            continue;
        }
        attackCount++;
        if(nowIndex + Ml + 1 < L){
            attackStops[nowIndex + Ml]--;
        }
        if(nowIndex >= 0){
            attackCount += attackStops[nowIndex];
        }
        
        nowIndex++;
    }
    cout << "YES";
}
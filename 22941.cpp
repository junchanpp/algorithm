#include <iostream>

using namespace std;

int main(){
    long long hp1, atk1, hp2, atk2;
    long long p, s;
    cin >> hp1 >> atk1 >>  hp2 >> atk2;
    cin >> p >> s;

    long long lastHp2 = hp2 + ((atk1 <= p || (hp2 % atk1 <= p && hp2 % atk1 > 0) ) ? s : 0);

    long long userTurn = lastHp2/atk1 + ((lastHp2 % atk1 > 0) ? 1 : 0);

    long long enermyTurn = hp1/atk2 + (hp1 % atk2 > 0 ? 1 : 0);

    if(userTurn <= enermyTurn){
        cout << "Victory!";
    }else {
        cout << "gg";
    }
}
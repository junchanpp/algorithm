#include <iostream>
using namespace std;
double bac(double n) {
    if(n <= 2)return n;
    else return 2 * bac(n-1) - 0.1 * bac(n-2);
}

double bac_tr(double n, double curr, double pp){
    if(n<= 1)return curr;
    else return bac_tr(n-1,2*curr-0.1*pp,curr);
}

double bac_tr(double n) {
    if(n <= 2) return n;
    else return bac_tr(n-1,2,1);
}


int main(){
    cout << bac(10) << endl;
    cout << bac_tr(10) << endl;
}
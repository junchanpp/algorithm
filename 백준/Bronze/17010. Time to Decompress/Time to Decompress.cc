#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int L;
    cin >> L;

    while(L--){
        int i;
        char c;
        cin >> i >> c;
        while(i--){
            cout << c;
        }
        cout << '\n';
    }
}
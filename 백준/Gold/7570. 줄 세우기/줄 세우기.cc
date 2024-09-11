#include <iostream>
#include <vector>

using namespace std;

int n;

int main (){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    vector<int> arr(n+1,0);

    int tmpMax = 0;

    for(int i = 0; i< n; i++){
        int tmp;
        cin >> tmp;
        tmpMax = max(tmpMax, arr[tmp] = (tmp >= 1 ? arr[tmp-1] : 0) + 1);
    }
    cout << n - tmpMax;
}
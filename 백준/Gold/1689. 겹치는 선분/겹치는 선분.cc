#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int N;//100만
vector<pair<int, int> > dSum;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i = 0 ; i < N; i++){
        int s , e;
        cin >> s >> e;
        dSum.push_back(make_pair(s, 1));
        dSum.push_back(make_pair(e, -1));
    }

    sort(dSum.begin(), dSum.end());

    int max = 1;
    int sum = 0;
    vector<pair<int, int> >::iterator iter;
    for(iter = dSum.begin(); iter != dSum.end(); iter++){
        sum = sum + iter->second;
        if(sum > max){
            max = sum;
        }
    }

    cout << max;


}
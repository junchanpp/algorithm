#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

vector<pair<int,int> > input;
vector<pair<int,int> > v;
int n;

int main(){
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin >> a >> b;
        input.push_back(make_pair(a,b));
    }

    sort(input.begin(),input.end());

    int left = input[0].first;
    int right = input[0].second;

    for(int i = 1 ; i < n; i++){
        if(right >= input[i].first){
            right = max(right, input[i].second);
        }else {
            v.push_back(make_pair(left,right));
            left = input[i].first;
            right = input[i].second;
        }
    }
    v.push_back(make_pair(left,right));


    int maxDist = v[0].second + v[0].second;
    int maxIndex = 0;
    int vectorSize = v.size();
    for(int i = 1 ; i < vectorSize; i++){
        if(maxDist >= v[i].first){
            maxIndex = i;
            if(maxDist <= v[i].second + (v[i].second-v[i].first)){
                maxDist = v[i].second + (v[i].second-v[i].first);
            }
        }
    }

    cout << v[maxIndex].second;
}
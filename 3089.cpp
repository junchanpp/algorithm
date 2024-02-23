#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int N, M;
vector<vector<int> > clovers;
unordered_map<int, vector<int> > mapByX;
unordered_map<int, vector<int> > mapByY;
string s;

pair<int, int> findClosestPoint(char c, int x, int y){
    int tempX, tempY;
    vector<int> v;
    int lo,hi,mid;
    switch(c){
        case 'U':
            v= mapByX[x];
            lo = 0, hi = v.size()-1;
            while(lo + 1< hi){
                mid = (lo+hi)/2;
                if(y > v[mid]){
                    lo = mid;
                }else {
                    hi = mid;
                }
            }
        
            tempY = v[hi] == y ? v[hi+1] : v[hi];
            tempX = x;
            break;
        case 'D':
            
            v= mapByX[x];
            lo = 0, hi = v.size()-1;
            while(lo+1 < hi){
                mid = (lo+hi)/2;
                if(y > v[mid]){
                    lo = mid;
                }else {
                    hi = mid;
                }
            }

            tempY = v[lo] == y ? v[lo-1] : v[lo];
            tempX = x;
            
            break;
        case 'R':
            v= mapByY[y];
            lo = 0, hi = v.size()-1;
            while(lo + 1< hi){
                mid = (lo+hi)/2;
                if(x > v[mid]){
                    lo = mid;
                }else {
                    hi = mid;
                }
            }
            tempX = v[hi] == x ? v[hi+1] : v[hi];
            tempY = y;
            break;
        case 'L':
            v= mapByY[y];
            lo = 0, hi = v.size()-1;
            while(lo+1 < hi){
                mid = (lo+hi)/2;
                if(x > v[mid]){
                    lo = mid;
                }else {
                    hi = mid;
                }
            }
            tempX = v[lo] == x ? v[lo-1] : v[lo];
            tempY = y;
            break;
        default :
            break;
    }
    return make_pair(tempX, tempY);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;

    for(int i = 0 ; i < N; i++){
        vector<int> v;
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back(temp1);
        v.push_back(temp2);
        clovers.push_back(v);
    }

    cin >> s;

    for(int i = 0 ; i < N; i++){
        if(mapByX.find(clovers[i][0]) != mapByX.end()){
            mapByX[clovers[i][0]].push_back(clovers[i][1]);
        }else {
            vector<int> v;
            v.push_back(clovers[i][1]);
            mapByX.insert(make_pair(clovers[i][0],v));
        }

        if(mapByY.find(clovers[i][1]) != mapByY.end()){
            mapByY[clovers[i][1]].push_back(clovers[i][0]);
        }else {
            vector<int> v;
            v.push_back(clovers[i][0]);
            mapByY.insert(make_pair(clovers[i][1],v));
        }
    }

    unordered_map<int, vector<int> >:: iterator iter;
    for(iter = mapByX.begin(); iter != mapByX.end(); iter++){
        sort((*iter).second.begin(),(*iter).second.end());
    }

    for(iter = mapByY.begin(); iter != mapByY.end(); iter++){
        sort((*iter).second.begin(),(*iter).second.end());
    }
    

    int nowX = 0;
    int nowY = 0;

    for(int i = 0 ; i < M; i++){
        pair<int, int> point = findClosestPoint(s[i], nowX, nowY);

        nowX = point.first;
        nowY = point.second;
    }


    cout << nowX << " " << nowY;


}
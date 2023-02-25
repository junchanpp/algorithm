#include <iostream>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

vector<pair<int,int> > point;
bool isVisited[50];
int N;

double getDistance(pair<int,int>& a, pair<int,int>& b){
    return sqrt(pow(a.first - b.first,2)+pow(a.second - b.second,2));
}
pair<int,int> getNewVector(pair<int,int>& a, pair<int,int>& b){
    return make_pair(a.first+b.first,a.second+b.second);
}

pair<int,int> solve(int n){
    if(n==2){
        int pointList[2];
        int index = 0;
        for(int i = 0;i<N;i++){
            if(isVisited[i]== false)pointList[index++] = i;
        }
        return getNewVector(point[pointList[0]],point[pointList[1]]);
    }
    int pointList[2];
    int index = 0;
    pair<int,int> minVector;
    isAssign = false;
    for(int i = 0;i<N;i++){
        if(isVisited[i]== false){
            if(index == 0){
                isVisited[i] = true;
                pointList[index++] = i;
                continue;
            }
            isVisited[i] = true;
            pair<int,int> currentVector = getNewVector(getNewVector(point[pointList[0]],point[i]),solve(n-2));
            if(isAssign ==false || sum < getDistance(minVector)){minSum = sum;}
            isVisited[i] = false;
        }
    }
    isVisited[pointList[0]] = false;
    return minSum;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i =0 ; i< N;i++){
            int x,y;
            cin >> x >> y;
            point.push_back(make_pair(x,y));
        }

        double answer = solve(N);
        cout << answer << endl;

    }
}
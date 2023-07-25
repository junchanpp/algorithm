#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#define INF 100000*100000+1;

using namespace std;


int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<pair<int, int> > pointList;
        vector<bool> temp(N,false);
        for(int i = 0; i<N/2;i++){
            temp[i] = true;
        }
        for(int i = 0; i <N;i++){
            int temp1, temp2;
            cin >> temp1 >> temp2;
            pointList.push_back(make_pair(temp1,temp2));
        }

        double distance = -1;

        do{
            int sumX = 0;
            int sumY = 0;
            for(int i = 0; i <N;i++){
                if(temp[i]== true){
                    sumX+=pointList[i].first;
                    sumY+=pointList[i].second;
                }else {
                    sumX-=pointList[i].first;
                    sumY-=pointList[i].second;
                }
            }
            double nowDistance = sqrt(pow(sumX,2)+pow(sumY,2));
            if(distance < 0 || nowDistance < distance)distance=nowDistance;
        }while(prev_permutation(temp.begin(),temp.end()));

        cout << fixed;
        cout.precision(12);
        cout << distance << endl;
    }
    return 0;
}
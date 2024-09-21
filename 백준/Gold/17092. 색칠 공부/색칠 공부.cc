#include <iostream>
#include <map>
#include <utility>
#include <set>

using namespace std;

set<pair<long long, long long> > blackPoint;
map<pair<long long, long long>, long long > square;
long long countBlackPoint[10]= {0,};
int dy[9] = {-2,-2,-2,-1,-1,-1,0,0,0};
int dx[9] = {-2,-1,0,-2,-1,0,-2,-1,0};

long long H, W, N;

int main(){
    cin >> H >> W >> N;

    for(int i = 0 ; i < N; i++){
        long long y, x;
        cin >> y >> x;
        blackPoint.insert(make_pair(--y, --x));
    }

    set<pair<long long, long long> >::iterator iter;
    for(iter = blackPoint.begin(); iter != blackPoint.end(); iter++){
        int y = iter->first;
        int x = iter->second;
        for(int i = 0 ; i < 9; i++){
            int newY = y + dy[i];
            int newX = x + dx[i];
            pair<int, int> squarePoint = make_pair(newY, newX);

            if(newY < 0 || newX < 0){
                continue;
            }
            if(newY >= H-2 || newX >= W-2){
                continue;
            }

            if(square.find(squarePoint) == square.end()){
                square.insert(make_pair(squarePoint, 0));
            }

            (square.find(squarePoint)->second)++;
        }
    }

    map<pair<long long, long long>, long long >::iterator iter2;
    for(iter2 = square.begin(); iter2 != square.end(); iter2++){
        countBlackPoint[iter2->second]++;
    }
    
    countBlackPoint[0] = (H-2) * (W-2) - square.size();

    for(int i = 0 ; i < 10; i++){
        cout << countBlackPoint[i] << '\n';
    }

}
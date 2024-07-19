// 2023-02-21 19:09:00 start

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

vector<pair<int,int> > cube;
int countCube = 0;

using namespace std;

int fill(int size){
    int index = -1;
    for(int i = 0 ; i< cube.size();i++){
        if(size >= cube[i].first && cube[i].second !=0){
            if(index == -1 || cube[i].first > cube[index].first)index = i;
        }
    }
    if(index == -1){
        return -1;
    }
    cube[index].second--;
    countCube++;
    return cube[index].first;
}

bool solve(int l,int w, int h){
    if(l==0 || w==0 || h==0){
        return true;
    }

    int min = l;
    if(w < min)min = w;
    if(h < min)min = h;
    
    int size = fill(min);
    if(size==-1)return false;
    if(min == l){
        return solve(l-size,size,size) && solve(l,w-size,size) && solve(l,w,h-size);
    }else if(min ==w){
        return solve(l-size,w,h) && solve(size, w-size,size)  && solve(size,w,h-size);
    }else {
        return solve(l-size,size,h) && solve(l,w-size,h) && solve(size, size,h-size);
    }
}


int main(){
    int length, width,height;
    int N;
    cin >> length >> width >> height;
    cin >> N;
    for(int i = 0; i <N;i++){
        int A,B;
        cin >> A >> B;
        cube.push_back(make_pair((int)pow(2,A),B));
    }

    bool result = solve(length, width, height);
    if(result == false){
        cout << -1;
        return 0;
    }

    cout << countCube;

}

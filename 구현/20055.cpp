#include<iostream>
#include<list>
#include<algorithm>

using namespace std;
int N,K;
int SIZE;
int value[400];
list<int> robotIndexList;

bool isStop(){
    int count = 0;
    for(int i =0; i< SIZE;i++){
        if(value[i] == 0){count++;
            if(count >= K){return true;}
        }
    }
    return false;
}

int main(){
    cin >> N >> K;

    SIZE = N*2;

    for(int i = 0 ; i <SIZE ;i++){
        cin >> value[i];
    }

    int inIndex = 0;
    int outIndex = N-1;
    int step = 0;

    while(!isStop()){
        step++;

        //1.
        inIndex--;
        outIndex--;
        if(inIndex < 0){
            inIndex = SIZE-1;
        }
        if(outIndex < 0){
            outIndex = SIZE-1;
        }
        for(list<int>::iterator iter = robotIndexList.begin() ; iter != robotIndexList.end();iter++){
            int nowIndex = *iter;
            if(outIndex == nowIndex){
                iter = robotIndexList.erase(iter);
            }
        }

        //2.
        for(list<int>::iterator iter = robotIndexList.begin() ; iter != robotIndexList.end();iter++){
            int nowIndex = *iter;
            int nextIndex = (nowIndex+1 >= SIZE) ? 0 : nowIndex+1;
            list<int>::iterator findIter = find(robotIndexList.begin(), robotIndexList.end(),nextIndex);
            if(findIter != robotIndexList.end() || value[nextIndex] ==0){
                continue;
            }
            *iter = nextIndex;
            value[nextIndex]--;
            if(outIndex == *iter){
                robotIndexList.erase(iter--);
            }
        }
        //3.
        list<int>::iterator findIter = find(robotIndexList.begin(), robotIndexList.end(),inIndex);
        if(findIter == robotIndexList.end() && value[inIndex] > 0){
            robotIndexList.push_back(inIndex);
            value[inIndex]--;
        }
    }

    cout << step;
}
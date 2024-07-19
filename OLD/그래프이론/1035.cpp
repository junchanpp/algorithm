#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int N = 0;
set<int> visited;

bool checkBit(const int& bit, const int& pos){
    return bit & (1 << pos);
}

int makeBitMask(const int& bit,const int& oldPos, const int& newPos){
    int newMask = bit;
    newMask -= 1<< oldPos;
    newMask |= 1<< newPos;
    return newMask;
}

bool isAllLink(const int& bitMask){
    for(int i = 0 ; i < 25;i++){
        if(checkBit(bitMask, i)){
            int count = 0;
            queue<int> q;
            q.push(i);
            bool visitedPos[25];
            for(int j = 0 ; j < 25;j++)visitedPos[j]=0;
            while(!q.empty()){
                int pos = q.front();
                q.pop();
                if(visitedPos[pos] == true)continue;
                visitedPos[pos] = true;
                count++;
                if(count == N)return true;
                if(pos+5 < 25 && checkBit(bitMask, pos+5))q.push(pos+5);
                if(pos-5 >= 0 && checkBit(bitMask, pos-5))q.push(pos-5);
                if(pos+1 < 25 && pos%5 != 4 && checkBit(bitMask, pos+1))q.push(pos+1);
                if(pos-1 >= 0 && pos%5 != 0 && checkBit(bitMask, pos-1))q.push(pos-1);
            }
            return false;
        }
    }
    return false;
}

int main(){
    int bitMaskInput = 0;
    for(int i = 0 ; i < 5;i++){
        string s;
        cin >> s;
        for(int j = 0; j <5;j++){
            if(s[j]=='*'){N++;bitMaskInput = bitMaskInput | (1 << (i*5+j));}
        }
    }
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    pq.push(make_pair(0,bitMaskInput));
    while(!pq.empty()){
        int cost = pq.top().first;
        int bitMask = pq.top().second;
        pq.pop();
        if(visited.find(bitMask)!=visited.end())continue;
        visited.insert(bitMask);
        if(isAllLink(bitMask)){
            cout << cost << endl;
            return 0;
        }
        for(int i = 0 ; i < 25; i++){
            if(checkBit(bitMask,i)){
                if(i+5 < 25 && !checkBit(bitMask,i+5))pq.push(make_pair(cost+1, makeBitMask(bitMask, i,i+5)));
                if(i-5 >= 0 && !checkBit(bitMask,i-5))pq.push(make_pair(cost+1, makeBitMask(bitMask, i,i-5)));
                if(i+1 < 25 && i%5 != 4 && !checkBit(bitMask,i+1))pq.push(make_pair(cost+1, makeBitMask(bitMask, i,i+1)));
                if(i-1 >= 0 && i%5 != 0 && !checkBit(bitMask,i-1))pq.push(make_pair(cost+1, makeBitMask(bitMask, i,i-1)));
            }
        }
    }
    return 0;
}
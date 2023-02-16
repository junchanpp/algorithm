#include <iostream>
#include <vector>
#include<memory.h>

using namespace std;

int n,w;
vector< pair<int,int> > events;
int memo[1001][1001];

int solve(int police1, int police2);

void printOrderPolice(int police1, int police2);

void tracking(int c1, int c2);

int main(){

    scanf("%d %d", &n, &w);

    events.push_back(make_pair(-1,-1));
    for(int i = 0; i< w; i++){
        int y,x;
        scanf("%d %d", &x,&y);

        events.push_back(make_pair(x,y));
    }
    memset(memo,-1,sizeof(memo));

    printf("%d\n", solve(0,0));

    tracking(0,0);
}

int getDist(pair<int,int> point1, pair<int,int> point2){
    return abs(point1.first-point2.first) + abs(point1.second-point2.second);
}


int solve(int police1, int police2){
    if(police1 == w || police2 == w){
        return 0;
    }
    if(memo[police1][police2] != -1) {
        return memo[police1][police2];
    }
    pair<int,int> point1 = police1 == 0 ? make_pair(1,1) : events[police1];
    pair<int,int> point2 = police2 == 0 ? make_pair(n,n) : events[police2];

    int nextIndex = max(police1, police2)+1;
    int dist1 = getDist(point1, events[nextIndex]) + solve(nextIndex, police2);
    int dist2 = getDist(point2, events[nextIndex]) + solve(police1,nextIndex);

    memo[police1][police2] = min(dist1,dist2);
    return memo[police1][police2];
}

void printOrderPolice(int police1, int police2){
    if(police1 == w || police2 == w){
        return;
    }


    pair<int,int> point1 = police1 == 0 ? make_pair(1,1) : events[police1];
    pair<int,int> point2 = police2 == 0 ? make_pair(n,n) : events[police2];

    int nextIndex = max(police1, police2) +1;
    int dist1 = getDist(point1, events[nextIndex]) + solve(nextIndex, police2);
    int dist2 = getDist(point2, events[nextIndex]) + solve(police1,nextIndex);

    if(memo[nextIndex][police2]+dist1 > memo[police1][nextIndex] + dist2){
        printf("2\n");
        printOrderPolice(police1,nextIndex);
    }else {
        printf("1\n");
        printOrderPolice(nextIndex,police2);
    }
}

void tracking(int c1, int c2) {
    if (c1 == w || c2 == w)
        return;
 
    pair<int,int> point1 = c1 == 0 ? make_pair(1,1) : events[c1];
    pair<int,int> point2 = c2 == 0 ? make_pair(n,n) : events[c2];
    int np = max(c1, c2) + 1;
    int n1 = getDist(point1, events[np]);
    int n2 = memo[np][c2] + n1;
 
    int m1 = getDist(point2, events[np]);
    int m2 = memo[c1][np] + m1;
 
    if (n2 > m2) {
        printf("2\n");
        tracking(c1, np);
    }
    else {
        printf("1\n");
        tracking(np, c2);
    }
}
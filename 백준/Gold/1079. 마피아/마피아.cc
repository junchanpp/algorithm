#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> degree;
int N;
vector<vector<int> > R;
int num;

vector<bool> isVisited;

int progressNight();
int progressDay();
void kill(int target);
void rebirth(int target);

void kill(int target){
    isVisited[target] = 1;
    for(int i = 0; i < N; i++){
        degree[i] += R[target][i];
    }
}

void rebirth(int target){
    isVisited[target] = 0;
    for(int i = 0; i < N; i++){
        degree[i] -= R[target][i];
    }
}

int progressNight(){
    int maxDays = 0;
    for(int i = 0; i < N; i++){
        if(isVisited[i] || i == num){
            continue;
        }
        kill(i);
        maxDays = max(maxDays, progressDay()+1);
        rebirth(i);
    }

    return maxDays;
}

int progressDay(){
    int index = -1;
    for(int i = 0 ; i < N; i++){
        if(!isVisited[i] && (index == -1 || degree[index] < degree[i])){
            index = i;
        }
    }
    if(index == num){
        return 0;
    }
    isVisited[index] = 1;
    int result = progressNight();
    isVisited[index] = 0;
    return result;
}

int main(){
    cin >> N;
    degree.assign(N,0);
    isVisited.assign(N,0);
    R.assign(N, vector<int>(N, 0));
    
    for(int i = 0; i < N; i++){
        cin >> degree[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> R[i][j];
        }
    }
    cin >> num;

    int result = 0;
    
    if(N % 2 == 0){
        result = progressNight();
    }else {
        result = progressDay();
    }

    cout << result;
}
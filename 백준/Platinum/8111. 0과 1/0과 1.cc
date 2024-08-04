#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int T, N;
vector<int> isVisited;
vector<int> prevNode;
vector<int> numbers;

int depth(int n){
    if(n == -1){
        return 1;
    }
    return depth(prevNode[n]) + 1;
}

void print(int n){
    if(n == -1){
        return;
    }
    print(prevNode[n]);
    cout << numbers[n];
}


bool solve(){
    prevNode[1] = -1;
    numbers[1] = 1;
    isVisited[1] = 1;

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        if(num % N == 0){
            return true;
        }
        int nextNum = (num * 10) % N;
        if(!isVisited[nextNum]){
            prevNode[nextNum] = num;
            isVisited[nextNum] = true;
            numbers[nextNum] = 0;
            q.push(nextNum);
        }
        nextNum = (num * 10 + 1) % N;
        if(!isVisited[nextNum]){
            prevNode[nextNum] = num;
            isVisited[nextNum] = true;
            numbers[nextNum] = 1;
            q.push(nextNum);
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;

    while(T--){
        cin >> N;
        prevNode.clear();
        numbers.clear();
        isVisited.clear();
        prevNode.assign(N+1, -1);
        isVisited.assign(N+1, 0);
        numbers.assign(N+1, 0);

        

        if(solve() && depth(0) <= 100){
            if(N == 1){
                cout << 1;
            }else {
                print(0);
            }
            
        }else {
            cout << "BRAK";
        }
        cout << '\n';

    }
}
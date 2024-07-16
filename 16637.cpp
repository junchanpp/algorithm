#include <iostream>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

int N;
string s;

int trans(int a) {
    return a -'0';
}

long long calc(int a, int b, char c){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
    }
    return a;
}

int main(){
    cin >> N;
    cin >> s;

    queue<pair<long long, int> > q;

    q.push(make_pair(trans(s[0]),0));
    long long max = LLONG_MIN;
    while(!q.empty()){
        
        long long result = q.front().first;
        int index = q.front().second;
        q.pop();
        if(index + 2 >= N){
            if(max < result){
                max = result;
            }
            continue;
        }

        q.push(make_pair(calc(result,trans(s[index+2]),s[index+1]), index+2));
        if(index + 4 < N){
            q.push(make_pair(calc(result, calc(trans(s[index+2]), trans(s[index+4]), s[index+3]), s[index+1]), index+4));
        }

    }

    cout << max << endl;

    return 0;
}
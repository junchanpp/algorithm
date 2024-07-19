#include <iostream>
#include <vector>

using namespace std;

int main(){
    int peopleCount;
    cin >> peopleCount;
    
    vector<int> v;
    v.push_back(0);//초기값 세팅 fibo(0) = 0
    v.push_back(1);//초기값 세팅 fibo(1) = 1
    int nowFibo = 1;
    while(nowFibo <= peopleCount){//사람수보다 작은 모든 경우
        nowFibo = v.at(v.size()-1) + v.at(v.size()-2);//피보나치 수열 알고리즘
        v.push_back(nowFibo);
    }
  
    int answer = 0;
    int index = v.size()-1;
    while(peopleCount > 0){//남은 사람 수가 0명이 될 때까지 진행
        if(peopleCount >= v.at(index)){
            peopleCount -= v.at(index);//남은 사람 수에 fibo(n) 빼기
            answer += v.at(index-1); //정답에 fibo(n-1) 더하기
        }
        index--;
    }
    cout << answer;

    return 0;
}
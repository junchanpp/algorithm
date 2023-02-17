//2023-02-16 23:38:53 start
//2023-02-17 00:27:59 end
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;

    int m = s.length();

    deque<string> oldQueue;
    deque<string> newQueue;
    oldQueue.push_back(s);
    int i;
    for(i = 0; i < k;i++){
        while(!oldQueue.empty()){
            string oldStr = oldQueue.front();
            oldQueue.pop_front();
            for(int a = 0; a < m;a++){
                for(int b = a+1; b < m;b++){
                    string newStr = oldStr;
                    swap(newStr[a], newStr[b]);
                    if(newStr[0] == '0'){
                        continue;
                    }
                    bool doPush = true;
                    for(int c = 0; c < newQueue.size();c++){
                        if(newStr.compare(newQueue.at(c)) ==0)doPush = false;
                    }
                    if(doPush)newQueue.push_back(newStr);
                }
            }
        }
        if(newQueue.empty()){
            cout << -1;
            return 0;
        }
        swap(oldQueue,newQueue);
        newQueue = deque<string>();
    }


    string max;
    while(!oldQueue.empty()){
        string newStr = oldQueue.front();
        oldQueue.pop_front();

        if(max.empty() || max.compare(newStr) < 0){
            max = newStr;
        }
    }

    cout << max;

    return 0;
}
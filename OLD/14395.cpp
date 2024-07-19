#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

long long s, t;

int getOrderValue(char c){
    switch(c){
        case '*' : 
            return 4;
        case '+' :
            return 3;
        case '-' :
            return 2;
        case '/' :
            return 1;
    }
    return 0;
}

struct cmp{
    bool operator()(pair<string, long long>& p1, pair<string, long long>& p2){
        string a = p1.first;
        string b = p2.first;
        if(a.size() == b.size()){
            for(int i = 0 ; i < a.size(); i++){
                if(a[i]!=b[i]){
                    return getOrderValue(a[i]) < getOrderValue(b[i]);
                }
            }
        }
        return a.size() > b.size();
    }
};

string solve(){
    
    priority_queue<pair<string, long long>, vector<pair<string, long long> >, cmp> pq;

    pq.push(make_pair("", s));
    pq.push(make_pair("/",1));

    while(!pq.empty()){// '-'와'/'는 하지 않는다. -는 0으로밖에 못만들고, /는 1로밖에 못만들기 때문
        pair<string, long long> node = pq.top();
        pq.pop();

        string s = node.first;
        long long nowValue = node.second;
        
        if(nowValue > t){// 더하기와 곱하기만 하기 때문에 현재 숫자가 t보다 커지면 더이상 진행하지 않는다.
            continue;
        }
        if(nowValue == t){
            return s;
        }
        if(nowValue == 0){
            continue;
        }

        pq.push(make_pair(s+'+',nowValue+nowValue));
        if(nowValue != 1){
            pq.push(make_pair(s+'*',nowValue*nowValue));
        }
        
    }  

    return "-1";
}

int main(){
    cin >> s >> t;
    if(s == t){
        cout << 0;
        return 0 ;
    }else if(t == 1){
        cout << '/';
        return 0;
    }else if(t == 0){//'-'를 사용하는 경우
        cout << '-';
        return 0;
    }

    cout << solve();

    return 0;
}
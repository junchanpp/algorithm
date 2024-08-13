#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> split(const string &s, char delimiter) {
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(stoi(token));
    }
    return tokens;
}


int n;
long long dSum[90001] = {0,};
long long totalSum[90001] = {0,};
long long result[90001] = {0,};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int type;
        cin >> type;
        if(type == 1){
            string s1, s2;
            cin >> s1 >> s2;
            int hh1,mm1,ss1;
            int hh2,mm2,ss2;

            hh1 = split(s1,':')[0];
            mm1 = split(s1,':')[1];
            ss1 = split(s1,':')[2];

            hh2 = split(s2,':')[0];
            mm2 = split(s2,':')[1];
            ss2 = split(s2,':')[2];

            ss1 = ss1 + 60 * mm1 + 60 * 60 * hh1;
            ss2 = ss2 + 60 * mm2 + 60 * 60 * hh2;
            dSum[ss1]++;
            dSum[ss2]--;
        }else {
            string s;
            cin >> s;

            totalSum[0] = dSum[0];
            for(int i = 1; i <= 90000; i++){
                totalSum[i] = totalSum[i-1] + dSum[i];
            }
            result[0] = totalSum[0];
            for(int i = 1; i <= 90000; i++){
                result[i] = result[i-1] + totalSum[i];
            }

            int hh,mm,ss;
            hh = split(s,':')[0];
            mm = split(s,':')[1];
            ss = split(s,':')[2];
            ss = ss + 60 * mm + 60 * 60 * hh;
            long long maxNum = 0;
            for(int i = ss; i < 90000; i++){
                
                maxNum = max(maxNum, result[i-1] - ((i - 1 - ss) < 0 ? 0 : result[i - 1 - ss]));
            }
            cout << maxNum;
        }
    }
}
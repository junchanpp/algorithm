#include <iostream>
#include <vector>
#include <string>


using namespace std;
int N;

int main(){
    cin >> N;
    string s;
    cin >> s;

    string pattern = "" + s.substr(0,1);

    int maxCount = 1;

    for(int i = 1; i < N; i++){
        int count = 1;
        bool isOk = true;
        for(int j = i; j < N; j+=pattern.size()){
            for(int k = 0; k < pattern.size(); k++){
                if(j+k >= N){
                    break;
                }
                if(s[j+k] != pattern[k]){
                    isOk = false;
                    break;
                }
            }
            if(!isOk){
                break;
            }else {
                count++;
            }
        }
        if(isOk){
            maxCount = max(maxCount, count);
        }
        pattern = pattern + s.substr(i,1);
    }

    cout << maxCount;

}
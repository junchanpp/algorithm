#include <iostream>

using namespace std;

int FF, FS, SF, SS;

int main(){
    cin >> FF >> FS >> SF >> SS;

    int answer =(FF > 0 || FS > 0) ? 0 : (SS + (SF == 0 ? 0 : 1));//3번 조건

    if(FS == 0){
        answer = max(answer, FF);
    }else{
        int result = FF + 1 + SS;
        if(SF == 0){
            answer = max(answer, result);
        }else {
            result += 1;
            result += min(SF-1, FS-1) * 2;
            if(FS > SF){
                result += 1;
            }
            
            answer = max(answer, result);
        }
    }

    cout << answer;

    
}
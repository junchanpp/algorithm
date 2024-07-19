//2023-02-16 21:10:18 start
//2023-02-16 21:53:50 end

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void swap(char* a, char* b);
void reverse(string& t);

int main (){
    string s,t;
    cin >> s >> t;

    while(s.length()<t.length()){

        if(t[t.length()-1] =='A'){
            t.pop_back();
        } else {
            t.pop_back();
            reverse(t);
        }
    }
    int result = s.compare(t) == 0 ? 1 : 0;
    cout << result << endl;
}
void reverse(string& t){
    int length = t.length();
    for(int i = 0; i < length/2; i++){
        swap(t[i],t[length-i-1]);
    }
    return;
}
void swap(char* a, char* b){
    char* temp;

    temp = a;
    a =b;
    b= temp;
}

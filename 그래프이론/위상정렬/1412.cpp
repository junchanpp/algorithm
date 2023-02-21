//2023-02-19 21:09:00 start
//2023-02-19 23:20:00 end


#include<iostream>
#include<string>
#include<deque>
#include<stack>
#include<algorithm>

using namespace std;

bool edge[51][51]={0,};
int n;

int main(){
    cin >> n;
    for(int i =0; i<n;i++){
        string s;
        cin >> s;
        for(int j =0;j<n;j++){
            if(s[j]=='Y') {
                edge[i][j]=true; 
            }
        }
    }

    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(edge[i][j]==true && edge[j][i] ==true){
                edge[i][j] =false;
                edge[j][i] = false;
            }
        }
    }

    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0;k<n;k++){
                if(edge[i][j] == true && edge[j][k]== true){
                    if(i ==k){
                        cout << "NO" << endl;
                        return 0;
                    }
                    edge[i][k] = true;
                }
            }
        }
    }

    cout<<"YES" << endl;
}